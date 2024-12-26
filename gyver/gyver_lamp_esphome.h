#pragma once

#include "light.h"
#include "constants.h"
#include "utility.h"
#include "effect_ticker.h"

class GyverLamp
{
  private:
    uint8_t cMode = EFF_WHITE_COLOR;

  public:
    GyverLamp();
    ~GyverLamp();

    void ShowFrame(uint8_t CurrentMode, esphome::Color current_color, light::AddressableLight *p_it);
};

GyverLamp::GyverLamp()
{
}

GyverLamp::~GyverLamp()
{
  FreeLeds();
}

void GyverLamp::ShowFrame(uint8_t CurrentMode, esphome::Color current_color, light::AddressableLight *p_it)
{
  InitLeds(p_it->size());

  if (cMode != CurrentMode)
  {
    cMode = CurrentMode;

    auto variant = id(fastled_variant).make_call();
    
    id(variant_min).publish_state(pgm_read_byte(&defaultSettings[CurrentMode][5]));
    id(variant_max).publish_state(pgm_read_byte(&defaultSettings[CurrentMode][6]));
    
    variant.set_value(pgm_read_byte(&defaultSettings[CurrentMode][2]));
    variant.perform();
    
    id(fastled_variant).traits.set_min_value(pgm_read_byte(&defaultSettings[CurrentMode][5]));
    id(fastled_variant).traits.set_max_value(pgm_read_byte(&defaultSettings[CurrentMode][6]));
   
    id(fastled_speed).traits.set_min_value(pgm_read_byte(&defaultSettings[CurrentMode][3]));
    id(fastled_speed).traits.set_max_value(pgm_read_byte(&defaultSettings[CurrentMode][4]));
   
    auto speed = id(fastled_speed).make_call();
    
    id(speed_min).publish_state(pgm_read_byte(&defaultSettings[CurrentMode][3]));
    id(speed_max).publish_state(pgm_read_byte(&defaultSettings[CurrentMode][4]));
    
    speed.set_value(pgm_read_byte(&defaultSettings[CurrentMode][1]));

    speed.perform();

  }
  currentMode = CurrentMode;
  loadingFlag = true;

  effectsTick();

  

  
  for (int i = 0; i < p_it->size(); i++)
  {
    (*p_it)[i] = Color(leds[i].r, leds[i].g, leds[i].b);
  }

  #if defined delay
  delay(1);
  #else
  esphome::delay(1);
  #endif
}

class GyverLamp gyver_lamp;
