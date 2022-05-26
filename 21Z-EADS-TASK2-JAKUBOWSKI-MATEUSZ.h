#include <iostream>
#include <stdio.h>
#include <stdexcept>

template<typename Key, typename Info>
class bi_ring
{
private:
        
    struct Node{
        Key key;
        Info info;
        Node* next;
        Node* prev;
    };
    Node* current;
    unsigned int count;
    Node* search(const Key& key, int occurance = 1){
        int temp_occurance = 0;
        if(isEmpty())return nullptr;
		Node* temp = current;
        //SEARCHING FOR A NODE WITH GIVEN KEY WITH SPECIFIED OCCURENCE
        //IF OCCURANCE IS NOT GIVEN THE DEFAULF VALUE IS 1
        do{
			if(temp->key == key){
            	temp_occurance++;
            }
			if(temp_occurance == occurance){
                return temp;
            }
			temp = temp->next;
		} while(temp != current);
		return nullptr;
    }
public:
    class const_iterator
    {   
        friend class bi_ring<Key,Info>;

    private:
        Node* itr;
        //ASSIGN GIVEN NODE TO ITRw
        const_iterator(Node* i){
            itr = i;
        }

    public:
        Key getKey() const{
            if(itr == nullptr){
                abort();
            }
            return itr->key;
        }
        Info getInfo() const{
           if(itr == nullptr){
               abort();
           }
            return itr->info;
        }
      
      
        //DEFAULT CONSTRUCTOR
        const_iterator(){
            itr = nullptr;
        }
        //ASSIGN TO ITR THE BEGINING OF SEQENCE
        const_iterator(const bi_ring<Key, Info>& src){
			itr = src.current;
		}
        //ASSIGN TO ITR THE NODE WITH GIVEN KEY
        const_iterator(const bi_ring<Key, Info>& seq, int key, int occurance){
			itr = seq.search(key, occurance);
		}
        //COPY CONSTURCTOR
        const_iterator(const const_iterator& src){
            itr = src.itr;
        }
        //INCREMENT BEFORE
        const_iterator& operator++(){
            if(itr != nullptr){
                itr = itr->next;
            }
        	return *this;
        }
        //INCREMENT AFTER
        const_iterator operator++(int a){
            const_iterator temp(*this);
        	++(*this);
        	return temp;
        }
        //DECREMENT BEFORE
        const_iterator operator--() {
            if(itr != nullptr){
                itr = itr->prev;
            }
        	return *this;
        }
        //DECREMENT AFTER
        const_iterator operator--(int) 
        {
            const_iterator temp(*this);
            --(*this);
            return temp;
        }
        //DEREFERENCING 
        Info operator*() const{
            if(itr == nullptr){
                abort();
            }
        	return itr->info;
        }
         //ASSIGNMENT OPERATOR
        const_iterator& operator=(const const_iterator& src) {
			itr = src.itr;
			return *this;
        }
        bool operator==(const const_iterator& right) const{
        	return (itr == right.itr); 				
        }
        bool operator!=(const const_iterator& right){
        	return (itr != right.itr);
        }
    };
    class iterator
    {
        friend class bi_ring<Key,Info>;
        
    private:
        Node* itr;
        iterator(Node* i){
            itr = i;
        }
    public:

        const Key& getKey() const{
            if(itr == nullptr) {
                abort();
            }
            return itr->key;
        }
        const Info& getInfo() const{
           if(itr == nullptr) {
                abort();
            }
            return itr->info;
        }
        //DEFAULT CONSTRUCTOR
        iterator(){
            itr = nullptr;
        }
        //ASSIGN TO ITR THE BEGINING OF SEQUENCE
        iterator(const bi_ring<Key, Info>& seq) {
			itr = seq.current;
		}
        //ASSIGN TO ITR THE NODE WITH GIVEN KEY
        iterator(const bi_ring<Key, Info>& seq, int key, int occurance) {
			itr = seq.search(key, occurance);
		}
        //HELPS WITH RETURNING THE "HEAD" TO BEGIN AND END
        iterator(const_iterator& ptr){
            itr = ptr.itr;
        }
        //COPY CONSTURCTOR
        iterator(const iterator& src){
            itr = src.itr;
        }
        //INCREMENT BEFORE
        iterator& operator++() {
            if(itr == nullptr) {
                throw std::out_of_range("List is empty");
            }
        	itr = itr->next;
        	return *this;
        }
        //INCREMENT AFTER
        iterator operator++(int a) {
            iterator temp(*this);
        	++(*this);
        	return temp;
        }
        //DECREMENT BEFORE
        iterator& operator--() 
        {
            if(itr == nullptr) {
                throw std::out_of_range("List is empty");
            }
            itr = itr->prev;
            return *this;
        }
        //DECREMENT AFTER
        iterator& operator--(int a)
        {
            iterator temp(*this);
            --(*this);
            return temp;
        }
        //DEREFERENCING 
        Info& operator*() const{
        	return getInfo();
        }
        //ASSIGNENT OPERATOR
        iterator& operator=(const iterator& src) {
			itr = src.itr;
			return *this;
        }
        bool operator==(const iterator& right) const{
        	return (itr == right.itr); 				
        }
        bool operator!=(const iterator& right){
        	return (itr != right.itr);
        } 
    };

public:
    const_iterator cbegin() const{
        return const_iterator(*this);
    }
    const_iterator cend() const{
        const_iterator end(*this);
        --end;
        return end;
    }
    iterator begin() const{
        return iterator(*this);
    }
    iterator end() const{
        iterator end(*this);
        --end;
        return end;
    }
    bi_ring(){
        current = nullptr;
        count = 0;
    }
    bi_ring(const bi_ring<Key,Info>& src){  
        count = 0;
        current = nullptr;
        *this = src;
    }
    ~bi_ring(){
        clearAll();
    }
    void clearAll(){
    	Node* ptr = current;
        Node* secPtr;
        if(ptr == nullptr){
            return; 
        }
    	do{
    		secPtr = ptr->next;
    		delete ptr;
    		ptr = secPtr;
    	}while(ptr != current);
        count = 0;
        current = nullptr;
    }
    void print() const{
        if(isEmpty()){
            return;
        }
        const_iterator a(*this);
        std::cout<<"\nList:\n";
        do{
            std::cout<< a.getKey() << " : "<< a.getInfo()<<"\n";
            a++;
        }while(a != cbegin());
        std::cout<<"\n\n";
    }
    unsigned int size() const{
        return count;
    }
    bool isEmpty() const {
        return current == nullptr;    
    }
    bi_ring& operator=(const bi_ring& src){
        if(this == & src){
            return *this;
        }
        clearAll();
    const_iterator a(src);
    do{
        push(a.getKey(), a.getInfo());
        a++;
    }while(a != src.cbegin());
        return *this;   
    }
    iterator push(const Key& key, const Info& info){
        Node* elem = new Node({key, info, nullptr, nullptr});
        if(current == nullptr){
            elem->next= elem;
            elem->prev = elem;
            current = elem;
        }else if(current->next == current){
            elem->next = current;
            current->next = elem;
            current->prev = elem;
            elem->prev = current;
        }else{
            elem->next = current;
            elem->prev = current->prev; 
            current->prev->next = elem;
            current->prev = elem;
        }
        count++;
        return iterator(elem);
    }
    iterator insertAfter(const Key& key, const Info& info, iterator position){
        if(current == nullptr){
            std::cout<<"There are no elements, action failed\n";
            return *this;
        }
        Node* elem = position.itr;
        //braced inizializer
        elem->next = new Node({key,info,elem->next, elem->prev});
        elem->next->next->prev = elem->next;
        count++;
    	return iterator(elem -> next);
        }
    iterator insertBefore(const Key& key, const Info& info, iterator position){
        if(current == nullptr){
            std::cout<<"\nThere are no elements, action failed\n";
            return *this;
        }
        Node* elem = position.itr;
        //braced inizializer
        elem->prev = new Node({key,info,elem->next, elem->prev});
        elem->prev->prev->next = elem->prev;
        elem->prev->next = elem;
        if(elem == current){
            current = elem->prev;
        }
        count++;
        return iterator(elem->prev);
    }
    iterator erase(iterator position){
        if(current == nullptr){
            std::cout<<"List is empty, action failed";
            return *this;
        }
        Node* elem = position.itr;
        if(elem->next == elem){
            Node* temp = current;
            delete temp;
            current = nullptr;
            --count;
        }else{
            elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
            Node* temp = elem;
            ++position;
            elem = position.itr;
            if(temp == current){
                current = elem;
            }
            delete temp;
            --count;
        }

        return *this;  
    }
};

template <typename Key, typename Info>
bi_ring<Key, Info> shuffle(const bi_ring<Key, Info>& first, unsigned int fcnt, const bi_ring<Key, Info>& second, unsigned int scnt, unsigned int reps) {
	if( !first.size() || !second.size() || !fcnt || !scnt || !reps ) {
		throw std::invalid_argument("Improper function call");
	}	
	typename bi_ring<Key, Info>::const_iterator first_itr(first), second_itr(second);
    bi_ring<Key, Info> outcome;

	for(int i = 0; i < reps; i++) {
		for(int k = 0; k < fcnt; k++) {
			outcome.push(first_itr.getKey(), first_itr.getInfo());
			first_itr++;
		}
		for(int k = 0; k < scnt; k++) {
			outcome.push(second_itr.getKey(), second_itr.getInfo());
			second_itr++;
		}
	}
	return outcome;
}