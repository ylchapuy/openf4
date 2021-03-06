/* 
 * Copyright (C) 2015 Antoine Joux, Vanessa Vitse and Titouan Coladon
 * 
 * This file is part of openf4.
 * 
 * openf4 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * openf4 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with openf4.  If not, see <http://www.gnu.org/licenses/>.
 */

  /**
  * \file monomial-array.h
  * \brief Declaration of class MonomialArray.
  * \author Vanessa VITSE, Antoine JOUX, Titouan COLADON
  */

#ifndef OPENF4_MONOMIAL_ARRAY_H
#define OPENF4_MONOMIAL_ARRAY_H

/** \cond */
#include "global.h"
#include <iostream>
#include <string>
#include <cassert>
#include <chrono>
#include <stdexcept>
#ifdef USE_OPENMP
#include <omp.h>
#endif
/** \endcond */
#include "monomial.h"


/** \namespace F4 
 * Group all the required tools used by the F4 algorithm.
 */
namespace F4
{
    /**
     * \class MonomialArray
     * \brief Represent a array of monomials.
     */
    class MonomialArray
    {
        public:
             
             /* Constructor */
             
             /**
              * \brief Constructor.
              * \param nbVariable: Number of variable of the polynomial ring.
              * \param capacity: Initial size of _monomialArray.
              */
             MonomialArray(int nbVariable, int capacity);
             
             /**
              * \brief Constructor.
              * \param nbVariable: Number of variable of the polynomial ring.
              * \param capacity: Initial size of _monomialArray.
              * \param degree: Initialise the monomial array up to monomial of degree "degree". 
              */
             MonomialArray(int nbVariable, int capacity, int degree);
             
             
             /* Destructor */
             
             /**
              * \brief Destructor.
              */
            ~MonomialArray();
            
            
            /* Miscellaneous */
            
            /**
             * \brief Modify the dynamic array _monomialArray.
             * \pre The array _nbMonomial must be set beforehand.
             */
             void setMonomialArray();
             
             /**
             * \brief Modify the static 2D array TABULATED_PRODUCT.
             * \pre Static variables NB_VARIABLE, NB_MONOMIAL and MONOMIAL_ARRAY must be set beforehand.
             * \param degree: Maximum degree of column monomials. The degree of row monomials is 1.
             */
             void setTabulatedProduct(int degree);
             
             /**
             * \brief Free the static 2D array NB_MONOMIAL.
             * \pre The static variables NB_VARIABLE must be set beforehand.
             */
             void freeTabulatedProduct();
             
             /**
             * \brief Get _monomialArray[numMon]._varlist[i].
             * \param numMon: Number of the monomial.
             * \param index: Index of a variable in varlist.
             * \return _monomialArray[numMon]._varlist[i].
             */
             uint8_t getNumVarlist(int numMon, int index);
             
             /**
             * \brief Multiply two monomials, using _tabulatedProduct if possible. Prefer numMon1<numMon2.
             * \param numMon1: Number of the first monomial.
             * \param numMon2: Number of the second monomial.
             * \return Number of the product intToMonomial[numMon1] * intToMonomial[numMon2].
             */
             int multNumMonomial(int numMon1, int numMon2);
             
             
             /* Access */
             
             /**
             * \brief Overload the operator [].
             * \return Reference on a monomial.
             */
            Monomial const & getNumMonomial(int index);
             
             /**
             * \brief Overload the operator [].
             * \return Reference on a monomial.
             */
            Monomial const & operator[](int index);
             
             
        
        private:
            std::vector<Monomial> _monomialArray ; /*!< Array of monomial */
            vector<int> * _tabulatedProduct; /*!< _tabulatedProduct[i][j] = number of the product intToMonomial[i] * intToMonomial[j] */
            int _nbVariable;   /*!< Number of variables of the polynomial ring. */
            size_t _size; /*!< Current size of _monomialArray */
            uint8_t * _varlistArray[128]; /*!< 2D array of varlist */
            int _varlistIndex; /*!< Next available row index in _varlistArray */
            int _numMaxRow; /*!< Number of rows in _tabulatedProduct. */
            int _numMaxColumn; /*!< Number of columns in _tabulatedProduct. */
            
        
    };
}

/** \cond */
#include "../src/monomial-array.inl"
/** \endcond */

#endif // OPENF4_MONOMIAL_ARRAY_H
