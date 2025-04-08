# Audio reactive LedStrip, GyverLamp, Fastled  Atom Lite Esphome + Light Effects

[![License][license-shield]][license]
[![ESPHome release][esphome-release-shield]][esphome-release]

[license-shield]: https://img.shields.io/static/v1?label=License&message=MIT&color=orange&logo=license
[license]: https://opensource.org/licenses/MIT
[esphome-release-shield]: https://img.shields.io/static/v1?label=ESPHome&message=2025.3&color=green&logo=esphome
[esphome-release]: https://GitHub.com/esphome/esphome/releases/

<img src="https://github.com/ananyevgv/led-strip/blob/main/atom.jpg" height="300" alt="Atom lite">


# Распайка микрофона
|MP34DT01         |Atom lite        |Примечание       | 
|-----------------|-----------------|-----------------|
|3V  |3V |3.3 Volt|
|GND |GPIO22 |GND|
|SEL |GPIO23 |WS I2S|
|CLK |GPIO19 |GND R or 3.3V L|
|DAT |GPIO33 |PDM_DATA I2S|

1. Скопируте папку ledstrip в /esphome/my_components
2. Cкопируйите led-strip.yaml

# Основано на:

https://github.com/zhujisheng/audio-reactive-led-strip

https://github.com/EgeHe/esphome-led-effects/blob/main/staircase_led.yaml

https://github.com/CODeRUS/esphome-fastled-matrix

https://github.com/soundstorm/esphome_led_effects

https://github.com/pashdown/ESPhome-effects/blob/main/effects.yaml

https://github.com/MvRens/ESPHomeLightEffects

https://github.com/kiasarecool/ESPhome_Lambda_Light_Effects

https://github.com/EgeHe/esphome-led-effects

https://github.com/jlboygenius/ESPHome_GEColorEffects

https://github.com/tallSequoia/ESPHomeLights

https://community.home-assistant.io/t/ws2811-ws2812-ideas-for-christmas/259262/3

https://community.home-assistant.io/t/share-your-esphome-light-effects/250294

https://github.com/pschatzmann/arduino-audio-tools/wiki/External-ADC

https://github.com/andrewjswan/esphome-config
