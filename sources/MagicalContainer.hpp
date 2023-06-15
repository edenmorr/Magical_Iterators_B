#pragma once
#include <vector>
#include <cmath>
#include<iostream>
#include <algorithm>
using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> elements;
        std::vector<size_t> prime;

    public:
     
    MagicalContainer() = default;

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

        void addElement(int element) // add element to the container in the ascending order
        {
        elements.push_back(element);
        sort(elements.begin(),elements.end());
        if(isPrime(element)){
            prime.push_back((size_t)element);
            sort(prime.begin(),prime.end());
            }
        }

        size_t size() const
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
            MagicalContainer &container;
            std::vector<int> iter;
            unsigned long int index;

        public:
            // Default constructor
            AscendingIterator(MagicalContainer &container)
                : container(container),index(0) {}

            // Destructor
            ~AscendingIterator(){};

            // Copy constructor
            AscendingIterator(const AscendingIterator &other)
                : container(other.container),index(other.index) {}
            // Move constructor
            AscendingIterator(AscendingIterator&& other) noexcept
                : container(other.container),index(other.index) {}

            // Move assignment operator
            AscendingIterator& operator=(AscendingIterator&& other) 
            {
                  if(&(this)->container != &other.container){
                    throw runtime_error("Prineiterator:= throws when iterators are pointing at different containers");
                }
            if (this != &other)
            {
            iter = other.iter;
            index = other.index;
            }
                return *this;
            }
            // Assignment operator "="
            AscendingIterator &operator=(const AscendingIterator&  other)
            {
                 if(&(this)->container != &other.container){
                    throw runtime_error("iterators pointing at different containers");
                }

            if (this != &other)
            {
            this->container = other.container;
            iter = other.iter;
            index = other.index;
            }
                return *this;
            }
          
            // Equality comparison (operator==)
            bool operator==(const AscendingIterator &other) const
            {
                return this->index == other.index;
            }

            // Inequality comparison (operator!=)
            bool operator!=(const AscendingIterator &other) const
            {
                return !(*this == other);
            }
            // Less than comparison (operator<)
            bool operator<(const AscendingIterator &other) const
            {
                return this->index < other.index;
            }

            // Greater than comparison (operator>)
             bool operator>(const AscendingIterator &other) const
            {
                return (this->index > other.index);
            }

            // Pre-increment operator (operator++)
            AscendingIterator &operator++()
            {
                 if(index < (this)->end().index){
                ++index;
                return *this;
            }
            else{
                throw std::runtime_error("AscendingIterator , finito got the end of the contianer!!");
            }
            }

            // Dereference operator (operator*)
            int operator*() const
            {
                return this->container.elements[index];
            }

            AscendingIterator begin()
            {
              AscendingIterator iterat(container);
              iterat.index = 0;
                return iterat; 
            }
            
            AscendingIterator end()
            {
            AscendingIterator iterat(container);
            iterat.index = container.elements.size();
                return iterat;
            }
        };

        class SideCrossIterator //////////////////////////////////////////////////// sidecrossiterator
        {

        private:
            MagicalContainer &container;
            std::vector<size_t> iter;
            unsigned long int index1;
            int counter = 0;

        public:
            unsigned long int getindex()
            {
                return this->index1;
            }
            // Default constructor
            SideCrossIterator( MagicalContainer &cont, bool revers = false) 
                : container(cont), index1(0) {}
            // Copy constructor
            SideCrossIterator(const SideCrossIterator &other)
                : container(other.container), iter(other.iter), index1(other.index1) {}
    
            // Destructor
            ~SideCrossIterator(){};

            // Move constructor
            SideCrossIterator(SideCrossIterator&& other) noexcept
                : container(other.container), iter(other.iter), index1(other.index1) {}

            // Move assignment operator
            SideCrossIterator& operator=(SideCrossIterator&& other) 
            {
                  if(&(this)->container != &other.container){
                    throw runtime_error("Prineiterator:= throws when iterators are pointing at different containers");
                }
            if (this != &other)
            {
            iter = other.iter;
            index1 = other.index1;
            }
                return *this;
            }
            // Assignment operator "="
            SideCrossIterator &operator=(const SideCrossIterator &other)
            {
                  if(&(this)->container != &other.container){
                    throw runtime_error("Prineiterator:= throws when iterators are pointing at different containers");
                }
            if (this != &other)
            {
            this->container = other.container;
            iter = other.iter;
            index1 = other.index1;
            }
                return *this;
            }
            // Less than comparison (operator<)
            bool operator<(const SideCrossIterator &other) const
            {
                return this->index1 < other.index1;
            }

            // Greater than comparison (operator>)
            bool operator>(const SideCrossIterator &other) const
            {
                return this->index1 > other.index1;
            }
            // Equality comparison (operator==)
            bool operator==(const SideCrossIterator &other) const{
                return this->index1 == other.index1;
            }

            // Inequality comparison (operator!=)
            bool operator!=(const SideCrossIterator &other) const{
                return !(*this == other);
            }

            // Pre-increment operator (operator++)
            SideCrossIterator &operator++(){ 
                if(index1 < (this)->end().index1){
                ++index1;
                if(this->counter < (this->container.elements.size()/2))
                {   
                    // cout << "counter =" << counter << endl; 
                    swap(this->container.elements,this->index1);
                    this->counter++;
                }
                return *this;
            }
            else{
                throw std::runtime_error("AscendingIterator , finito got the end of the contianer!!");
            } 
            }
            

            // Dereference operator (operator*)
            void swap(std::vector<int> &iter,unsigned long int index)
            {
                int temp = iter[iter.size()-1];
                iter[iter.size()-1] = iter[index];
                iter[index] = temp;
            }

            int operator*() {
            
                return this->container.elements[this->index1];
            }

            SideCrossIterator begin(){
            SideCrossIterator iterat(container);
            iterat.index1 = 0;
                return iterat; 
            }

            SideCrossIterator end()
            {
            SideCrossIterator iterat(container);
            iterat.index1 = container.elements.size();
                return iterat;
            }
            };

        class PrimeIterator /////////////////////////// primeIterator
        {
        private:
            MagicalContainer &container;
            std::vector<size_t> iter;
             size_t index;
             size_t temp;


        public:
            // Default constructor
            PrimeIterator( MagicalContainer &cont): container(cont){
            auto endIterator = cont.prime.end();
            if (cont.size() == 0) {
            // *this = cont.prime.end();    /////////////////////////////////// not working !!!!!!!!
            } 
            
            this->index = 0;
            this->temp = 0;
            }

            // Destructor
            ~PrimeIterator(){};
            
            // Copy constructor
            PrimeIterator(const PrimeIterator& other)
                : container(other.container),index(other.index),temp(other.temp)
            {}
             // Move constructor
            PrimeIterator(PrimeIterator&& other) noexcept
                : container(other.container),index(other.index),temp(other.temp){}

            // Move assignment operator
            PrimeIterator& operator=(PrimeIterator&& other) {
            if(&(this)->container != &other.container){
                    throw runtime_error("Prineiterator:= throws when iterators are pointing at different containers");
                }
                (this)->container = other.container;
                (this)->index = other.index;
                (this)->temp = other.temp;
                return *(this);
            }

            // Assignment operator "="
            PrimeIterator& operator=(const PrimeIterator& other)
            {
           
            if(&(this)->container != &other.container){
                    throw runtime_error("iterators pointing at different containers");
                }
                (this)->container = other.container;
                (this)->index = other.index;
                (this)->temp = other.temp;
                return *(this);   

            }


            // Equality comparison (operator==)
            bool operator==(const PrimeIterator &other) const{
            // return (&(this)->container != &other.container||((this)->index != other.index))? false:true;
            if(this->index != other.index)
            {
                // cout << "123test" <<endl;
                return false;
            }
            else
            {
                return true;
            }
            }

            // Inequality comparison (operator!=)
            bool operator!=(const PrimeIterator &other) const{
                return !(*this == other);
            }

            // Less than comparison (operator<)
            bool operator<(const PrimeIterator& other) const
            {
                return this->index < other.index; ;
            }

            // Greater than comparison (operator>)
            bool operator>(const PrimeIterator& other) const
            {
                return this->index > other.index;      
                      }

            // Pre-increment operator (operator++)
            PrimeIterator &operator++(){
            if(*this == this->end()){
                throw std::runtime_error(" no more prime elements");
            }
            // if(container.size()==0){
            //     this = nullptr;
            // }
            
            if((this)->temp+1 == container.prime.size()){
                index = end().index;
                return *this;
            }        
            if((this)->temp < container.prime.size()){
                (this)->temp++;
                (this)->index = container.prime[(this)->temp];
                return (*this);
            }
            else{
                throw std::runtime_error("blabla");
            }

            }

            // Dereference operator (operator*)
            int operator*() {
                int temp = (this)->container.prime[this->temp];
                return temp;
            }

            PrimeIterator begin(){
                if(container.prime.size() > 0){
                PrimeIterator beginIter(this->container);
                beginIter.index = 0;
                return beginIter;
            }
            else{
                throw std::runtime_error("no prime numbers in the container");
            }
        }
            
        PrimeIterator end(){
        PrimeIterator iterator(container);
        iterator.index = iterator.container.prime.size()+1;
        return iterator;
        }
        };
    };
} 
