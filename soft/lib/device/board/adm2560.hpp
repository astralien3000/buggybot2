/*
    Aversive++
    Copyright (C) 2014 Eirbot

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ADM2560_HPP
#define ADM2560_HPP

#include "../micro/avr.hpp"

//! \class ADM2560 adm2560.hpp <board/adm2560.hpp>
//! \brief Class providing meta-data for the Arduino Mega 2560 board.
class ADM2560 {
  //! \brief Private default constructor to prevent instanciation.
  ADM2560();

public:
  //! \class ADM2560::Pinmap adm2560.hpp <board/adm2560.hpp>
  //! \brief Pinmap for Arduino Mega 2560 board. D stands for digital pins and A for analog pins.
  class Pinmap {
    //! \brief Private default constructor to prevent instanciation.
    Pinmap();

  public:
    static constexpr int D0  = avr::pin('e', 0);
    static constexpr int D1  = avr::pin('e', 1);
    static constexpr int D2  = avr::pin('e', 4);
    static constexpr int D3  = avr::pin('e', 5);
    static constexpr int D4  = avr::pin('g', 5);
    static constexpr int D5  = avr::pin('e', 3);
    static constexpr int D6  = avr::pin('h', 3);
    static constexpr int D7  = avr::pin('h', 4);
    static constexpr int D8  = avr::pin('h', 5);
    static constexpr int D9  = avr::pin('h', 6);
    static constexpr int D10 = avr::pin('b', 4);
    static constexpr int D11 = avr::pin('b', 5);
    static constexpr int D12 = avr::pin('b', 6);
    static constexpr int D13 = avr::pin('b', 7);
    static constexpr int D14 = avr::pin('j', 1);
    static constexpr int D15 = avr::pin('j', 0);
    static constexpr int D16 = avr::pin('h', 1);
    static constexpr int D17 = avr::pin('h', 0);
    static constexpr int D18 = avr::pin('d', 3);
    static constexpr int D19 = avr::pin('d', 2);
    static constexpr int D20 = avr::pin('d', 1);
    static constexpr int D21 = avr::pin('d', 0);
    static constexpr int D22 = avr::pin('a', 0);
    static constexpr int D23 = avr::pin('a', 1);
    static constexpr int D24 = avr::pin('a', 2);
    static constexpr int D25 = avr::pin('a', 3);
    static constexpr int D26 = avr::pin('a', 4);
    static constexpr int D27 = avr::pin('a', 5);
    static constexpr int D28 = avr::pin('a', 6);
    static constexpr int D29 = avr::pin('a', 7);
    static constexpr int D30 = avr::pin('c', 7);
    static constexpr int D31 = avr::pin('c', 6);
    static constexpr int D32 = avr::pin('c', 5);
    static constexpr int D33 = avr::pin('c', 4);
    static constexpr int D34 = avr::pin('c', 3);
    static constexpr int D35 = avr::pin('c', 2);
    static constexpr int D36 = avr::pin('c', 1);
    static constexpr int D37 = avr::pin('c', 0);
    static constexpr int D38 = avr::pin('d', 7);
    static constexpr int D39 = avr::pin('g', 2);
    static constexpr int D40 = avr::pin('g', 1);
    static constexpr int D41 = avr::pin('g', 0);
    static constexpr int D42 = avr::pin('l', 7);
    static constexpr int D43 = avr::pin('l', 6);
    static constexpr int D44 = avr::pin('l', 5);
    static constexpr int D45 = avr::pin('l', 4);
    static constexpr int D46 = avr::pin('l', 3);
    static constexpr int D47 = avr::pin('l', 2);
    static constexpr int D48 = avr::pin('l', 1);
    static constexpr int D49 = avr::pin('l', 0);
    static constexpr int D50 = avr::pin('b', 3);
    static constexpr int D51 = avr::pin('b', 2);
    static constexpr int D52 = avr::pin('b', 1);
    static constexpr int D53 = avr::pin('b', 0);

    static constexpr int A0  = avr::pin('f', 0);
    static constexpr int A1  = avr::pin('f', 1);
    static constexpr int A2  = avr::pin('f', 2);
    static constexpr int A3  = avr::pin('f', 3);
    static constexpr int A4  = avr::pin('f', 4);
    static constexpr int A5  = avr::pin('f', 5);
    static constexpr int A6  = avr::pin('f', 6);
    static constexpr int A7  = avr::pin('f', 7);
    static constexpr int A8  = avr::pin('k', 0);
    static constexpr int A9  = avr::pin('k', 1);
    static constexpr int A10 = avr::pin('k', 2);
    static constexpr int A11 = avr::pin('k', 3);
    static constexpr int A12 = avr::pin('k', 4);
    static constexpr int A13 = avr::pin('k', 5);
    static constexpr int A14 = avr::pin('k', 6);
    static constexpr int A15 = avr::pin('k', 7);
  };
};

#endif//ADM2560PINMAP_HPP
