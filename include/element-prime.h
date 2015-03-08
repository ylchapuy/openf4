/* 
 * Copyright (C) 2010 Antoine Joux and Vanessa Vitse 

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 */

  /**
  * \file element-prime.h
  * \brief Declaration of class ElementPrime.
  * \author Vanessa VITSE, Antoine JOUX, Titouan COLADON
  */

#ifndef F4_ELEMENT_PRIME_H
#define F4_ELEMENT_PRIME_H

#include <iostream>
#include <string.h>
#include <cassert>

/** \namespace F4 
 * Group all the required tools used by the F4 algorithm.
 */
namespace F4
{
    /**
     * \class ElementPrime
     * Represent an element of a prime field.
     */
    template <typename baseType>
    class ElementPrime
    {
        public:
            
            // static methods
            
            /**
             * \brief Set the static variable MODULO.
             * \param modulo: Characteristic of the base field.
             */
            static void setModulo(unsigned int modulo);
            
            /**
             * \brief Get the static variable MODULO.
             * \return Characteristic of the base field.
             */
            static unsigned int getModulo();
            
            
            // Constructor
            
            /**
             * \brief Constructor.
             * \pre The static variable MODULO must be set beforehand.
             * \param element: baseType element.
             */
            ElementPrime(baseType element);
            
            /**
             * \brief Constructor.
             * \pre The static variable MODULO must be set beforehand.
             */
            ElementPrime();
            
            
            // Miscellaneous
            
            /**
             * \brief Inverse this according to the base field.
             * \pre The static variable MODULO must be set beforehand. Beware, baseType must be signed.
             */
            ElementPrime inverse() const;
            
            /**
             * \brief Print the element.
             */
            void printElementPrime (std::ostream & stream = std::cout) const;
            
            /**
             * \brief Compare ElementPrime.
             * \pre The static variable MODULO must be set beforehand.
             * \param element: ElementPrime.
             * \return  true if this==element.
             * \return  false if otherwise.
             */
            bool isEqual(ElementPrime const & element) const;
            
            /**
             * \brief Compare ElementPrime.
             * \pre The static variable MODULO must be set beforehand.
             * \param element: baseType.
             * \return  true if this==element.
             * \return  false if otherwise.
             */
            bool isEqual(baseType element) const;
            
            /**
             * \brief Test if this is nul.
             * \return  true if this==element.
             * \return  false otherwise.
             */
            bool isZero() const;
            
            
            // Internal operators
            
            /**
             * \brief Overload the operator +=.
             * \pre The static variable MODULO must be set beforehand.
             * \param element: Element of a prime field.
             * \return Reference on this.
             */
            ElementPrime & operator+=(ElementPrime const & element); 
            
            /**
             * \brief Overload the operator -=.
             * \pre The static variable MODULO must be set beforehand.
             * \param element: Element of a prime field.
             * \return Reference on this.
             */
            ElementPrime & operator-=(ElementPrime const & element); 
            
            /**
             * \brief Overload the operator *=.
             * \pre The static variable MODULO must be set beforehand.
             * \param element: Element of a prime field.
             * \return Reference on this.
             */
            ElementPrime & operator*=(ElementPrime const & element); 
            
            /**
             * \brief Overload the operator /=.
             * \pre The static variable MODULO must be set beforehand.
             * \param element: Element of a prime field.
             * \return Reference on this.
             */
            ElementPrime & operator/=(ElementPrime const & element); 
            
        private:
            baseType _element; /*!< Represent an element of the field of characteristic MODULO */
            
            static unsigned int MODULO; /*!< Characteristic of the base field */
    };
    
    /**
     * \brief Overload the operator <<.
     * \return ostream: Stream.
     */
    template <typename baseType>
    std::ostream & operator<<(std::ostream & stream, ElementPrime<baseType> const & element);
    
    /**
     * \brief Overload the operator *.
     * \return element1 * element2.
     */
    template <typename baseType>
    ElementPrime<baseType> operator * (ElementPrime<baseType> const & element1, ElementPrime<baseType> const & element2);
    
    /**
     * \brief Overload the operator /.
     * \return element1 / element2.
     */
    template <typename baseType>
    ElementPrime<baseType> operator / (ElementPrime<baseType> const & element1, ElementPrime<baseType> const & element2);
    
    /**
     * \brief Overload the operator +.
     * \return element1 + element2.
     */
    template <typename baseType>
    ElementPrime<baseType> operator + (ElementPrime<baseType> const & element1, ElementPrime<baseType> const & element2);
    
    /**
     * \brief Overload the operator -.
     * \return element1 - element2.
     */
    template <typename baseType>
    ElementPrime<baseType> operator - (ElementPrime<baseType> const & element1, ElementPrime<baseType> const & element2);
    
    /**
     * \brief Overload the operator -.
     * \return -element.
     */
    template <typename baseType>
    ElementPrime<baseType> operator - (ElementPrime<baseType> const & element);
    
    /**
     * \brief Overload the operator ==.
     * \return true if element1==element2.
     * \return false otherwise.
     */
    template <typename baseType>
    ElementPrime<baseType> operator==(ElementPrime<baseType> const & element1, ElementPrime<baseType> const & element2);
    
    /**
     * \brief Overload the operator ==.
     * \return true if element1==element2.
     * \return false otherwise.
     */
    template <typename baseType>
    ElementPrime<baseType> operator==(ElementPrime<baseType> const & element1, baseType element2);
    
    /**
     * \brief Overload the operator !=.
     * \return true if element1!=element2.
     * \return false otherwise.
     */
    template <typename baseType>
    ElementPrime<baseType> operator!=(ElementPrime<baseType> const & element1, ElementPrime<baseType> const & element2);
    
    /**
     * \brief Overload the operator !=.
     * \return true if element1!=element2.
     * \return false otherwise.
     */
    template <typename baseType>
    ElementPrime<baseType> operator!=(ElementPrime<baseType> const & element1, baseType element2);
}

#include "../src/element-prime.inl"

#endif // F4_ELEMENT_PRIME_H