/* -*- mode: c++ -*-
 * Kaleidoscope-KeyLogger -- A key logger
 * Copyright (C) 2016, 2017, 2018  Keyboard.io, Inc
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <Kaleidoscope.h>
#include <Kaleidoscope-KeyLogger.h>

namespace kaleidoscope {
namespace plugin {

EventHandlerResult KeyLogger::onKeyswitchEvent(Key &mapped_key, KeyAddr key_addr, uint8_t key_state) {
  if (!keyToggledOn(key_state) && !keyToggledOff(key_state))
    return EventHandlerResult::OK;
  if (key_state & INJECTED)
    return EventHandlerResult::OK;

  Serial.print(F("KL: row="));
  Serial.print(key_addr.row(), DEC);
  Serial.print(F(", col="));
  Serial.print(key_addr.col(), DEC);
  Serial.print(F(", pressed="));
  Serial.print(keyToggledOn(key_state), DEC);
  Serial.print(F(", layerState="));
  Serial.print(Layer.getLayerState(), BIN);
  Serial.print(F(", mapped_key.flags="));
  Serial.print(mapped_key.getFlags(), BIN);
  Serial.print(F(", mapped_key.keyCode="));
  Serial.print(mapped_key.getKeyCode(), HEX);
  Serial.print(F(", timestamp="));
  Serial.println(millis(), DEC);

  return EventHandlerResult::OK;
}

}
}

kaleidoscope::plugin::KeyLogger KeyLogger;
