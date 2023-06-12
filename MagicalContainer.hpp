#pragma once
#include <vector>
#include <cmath>
#include<iostream>
#include <algorithm>

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> elements;

    public:
        void addElement(int element) // add element to the container in the ascending order
        {
        elements.push_back(element);
        sort(elements.begin(),elements.end());
    
        // auto iterat = elements.begin();
        // while (iterat != elements.end() && *iterat < element) {
        //     ++iterat;
        // }
        // // Insert the element at the found position
        // elements.insert(iterat, element);
        }

        int size() const
        {
            return elements.size();
        }
       
        void removeElement(int element) // Removes an element from the container
        { 
            for (auto it = elements.begin(); it != elements.end(); ++it) { // Find the element in the container
                if (*it == element) {  // If the element is found, remove it from the container
                    elements.erase(it);
                return;
                }
            }
            throw std::runtime_error("Element not found");
        }

        class AscendingIterator
        {

        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator iter;

        public:
            // Default constructor
            AscendingIterator(const MagicalContainer &container)
                : container(container), iter(container.elements.begin()) {}

            // Destructor
            ~AscendingIterator(){};

            // Copy constructor
            AscendingIterator(const AscendingIterator &other)
                : container(other.container), iter(other.iter) {}
            // Move constructor
            AscendingIterator(AscendingIterator&& other) noexcept
                : container(other.container), iter(other.iter) {}

            // Move assignment operator
            AscendingIterator& operator=(AscendingIterator&& other) noexcept
            {
                if (this != &other) {
                    iter = (other.iter);
                }
                return *this;
            }
            // Assignment operator "="
            AscendingIterator &operator=(const AscendingIterator& other)
            {
            if (this != &other) {
                // container = other.container;
                iter = other.iter;
            }
                return *this;
            }
            // // Move constructor
            // AscendingIterator(AscendingIterator&&) = default;

            // // Move assignment operator
            // AscendingIterator& operator=(AscendingIterator&&) = default;

            // Equality comparison (operator==)
            bool operator==(const AscendingIterator &other) const
            {
                return iter == other.iter;
            }

            // Inequality comparison (operator!=)
            bool operator!=(const AscendingIterator &other) const
            {
                return !(*this == other);
            }
            // Less than comparison (operator<)
            bool operator<(const AscendingIterator &other) const
            {
                return *iter < *other.iter;
            }

            // Greater than comparison (operator>)
             bool operator>(const AscendingIterator &other) const
            {
                return *iter > *other.iter;
            }

            // Pre-increment operator (operator++)
            AscendingIterator &operator++()
            {
                ++iter;
                return *this;
            }

            // Dereference operator (operator*)
            int operator*() const
            {
                return *iter;
            }
            AscendingIterator begin()
            {
            AscendingIterator iterat(container);
                if (!container.elements.empty())
                {
                  iterat.iter = container.elements.begin();
                }
                return iterat;
            }
            
            AscendingIterator end()
            {
            AscendingIterator iterat(container);
            iterat.iter = container.elements.end();
                return iterat;
                return AscendingIterator(container);
            }
        };

        class SideCrossIterator
        {

        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator iter;
            bool isReversed;

        public:
            // Default constructor
            SideCrossIterator(const MagicalContainer &cont, bool revers = false) 
                : container(cont), isReversed(revers) {}

            // Copy constructor
            SideCrossIterator(const SideCrossIterator &other)
                : container(other.container), iter(other.iter), isReversed(other.isReversed) {}
    
            // Destructor
            ~SideCrossIterator(){};
            // Move constructor
            SideCrossIterator(SideCrossIterator&& other) noexcept
                : container(other.container), iter(other.iter), isReversed(other.isReversed) {}

            // Move assignment operator
            SideCrossIterator& operator=(SideCrossIterator&& other) noexcept
            {
            if (this != &other)
            {
            // container = other.container;
            iter = other.iter;
            isReversed = other.isReversed;
            }
                return *this;
            }
            // Assignment operator "="
            SideCrossIterator &operator=(const SideCrossIterator &other)
            {
            if (this != &other)
            {
            // container = other.container;
            iter = other.iter;
            isReversed = other.isReversed;
            }
                return *this;
            }
            // Less than comparison (operator<)
            bool operator<(const SideCrossIterator &other) const
            {
                return iter < other.iter;
            }

            // Greater than comparison (operator>)
            bool operator>(const SideCrossIterator &other) const
            {
                return iter > other.iter;
            }
            // Equality comparison (operator==)
            bool operator==(const SideCrossIterator &other) const{
                return iter == other.iter;
            }

            // Inequality comparison (operator!=)
            bool operator!=(const SideCrossIterator &other) const{
                    return !(*this == other);
            }

            // Pre-increment operator (operator++)
            SideCrossIterator &operator++(){ 
                // if (container.elements.begin() == container.elements.end())
                // {
                //     throw std::runtime_error("the iterator is at the end");
                // }
                // // if (this->container.elements.begin() == this->container.elements.end())
                // // {
                // //     this->container.elements.begin() = this->container.elements.end();
                // //     this->isReversed = false;
                // //     return *this;
                // // }
                //    if (isReversed)
                //     {
                //         ++iter;
                //     }
                //     --iter;
                //     return *this;
                // }
        //         unsigned long int index;
        //            if(index < container.size()){
        //     size_t size = container.size();
        //     if(index == size/2){
        //         index = size;
        //     }
        //     else if (index < size / 2)
        //     {
        //         index--;
        //     }
        //     else{
        //         index++;
        //     }
        //     return *this;
        // }
        // else{
        //     throw std::runtime_error("finito got the end of the container (sideCrossIterator)");
        // }
return *this;
    }
            
            
            // Dereference operator (operator*)
            int operator*() const{
                return *iter;
            }

            SideCrossIterator begin(){
            SideCrossIterator iterat(container);
            if (!container.elements.empty())
            {
                iterat.iter = container.elements.begin();
            }
            return iterat; 
            }

            SideCrossIterator end(){
            SideCrossIterator iterat(container);
            iterat.iter = container.elements.end();
            return iterat;
            }
        };

        class PrimeIterator
        {

        private:
            const MagicalContainer &container;
            std::vector<int>::const_iterator iter;

            bool static isPrime(int num) {
                if(num<2){
                    return false;
                }
            for(int i=2; i<=std::sqrt(num);++i){
                if(num % i == 0){
                    return false;
                }
            }
            return true;
            }

        public:
            // Default constructor
            PrimeIterator(const MagicalContainer &cont)
                : container(cont), iter(container.elements.begin())
            {
                while ((iter != container.elements.end() && !isPrime(*iter)))
                {
                    ++iter;
                }
                
            }
            // Destructor
            ~PrimeIterator(){};
            
            // Copy constructor
            PrimeIterator(const PrimeIterator& other)
                : container(other.container), iter(other.iter)
            {
            }
             // Move constructor
            PrimeIterator(PrimeIterator&& other) noexcept
                : container(other.container), iter(other.iter){}

            // Move assignment operator
            PrimeIterator& operator=(PrimeIterator&& other) noexcept
            {
                if (this != &other)
                {
                    // container = other.container;
                    iter = other.iter;
                }
                return *this;
            }
            // Assignment operator "="
            PrimeIterator& operator=(const PrimeIterator& other)
            {
                if (this != &other)
                {
                    // container = other.container;
                    iter = other.iter;
                }
                return *this;
            }
            // Equality comparison (operator==)
            bool operator==(const PrimeIterator &other) const{
                return iter == other.iter;
            }

            // Inequality comparison (operator!=)
            bool operator!=(const PrimeIterator &other) const{
                return !(*this ==other);
            }

            // Less than comparison (operator<)
            bool operator<(const PrimeIterator& other) const
            {
                return *iter < *other.iter;
            }

            // Greater than comparison (operator>)
            bool operator>(const PrimeIterator& other) const
            {
                return *iter > *other.iter;
            }

            // Pre-increment operator (operator++)
            PrimeIterator &operator++(){
            ++iter;
                while (iter != container.elements.end() && !isPrime(*iter))
                {
                   ++iter;
                }
                return *this;
            }

            // Dereference operator (operator*)
            int operator*() const{
                return *iter;
            }

            PrimeIterator begin(){
                return PrimeIterator(container);
            }
            PrimeIterator end(){
                return PrimeIterator(container);
            }
        };
    };
} 
