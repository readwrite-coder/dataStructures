#ifndef ARRAYLIST_H
#define ARRAYLIST_H
template <typename T>
//______________________
class arrayList {
	//______________________
	public:
	arrayList();
	//______________________
	int size(); //return the size of the current list.
	bool empty(); //returns true if the list is empty.
	//______________________
	void push_back (T val);
	void insert (int index, T val); //append the value at the specified index. 
	T get (int index); //return the value at the specified index of the list.
	//______________________
	void clear(); //delete the entire list.
	void remove(int index); //remove the list item at the specified index. 
	//______________________
	private:
	T * start;
	int arrayCount; 
	int arrayCapacity;
	//______________________
};
//______________________
template <typename T>
arrayList<T>::arrayList(){
	arrayCount = 0;
	arrayCapacity = 2;
	start = new T[arrayCapacity];
}

template <typename T>
int arrayList<T>::size(){
	return arrayCount;
}
template <typename T>
bool arrayList<T>::empty(){
	return this->size() == 0;
}
template <typename T>
void arrayList<T>::push_back(T element){
	if(arrayCount == arrayCapacity){
		std::string * temp = new std::string[arrayCapacity*2];
		arrayCapacity *= 2;
		for(int i = 0; i < arrayCount; i++){
			temp[i] = start[i];
		}
		start = temp;
	}
	start[arrayCount] = element;
	arrayCount++;
}
template <typename T>
void arrayList<T>::insert(int index, T val){
	if(index > this->arrayCount || index < 0){
		return; 
	}
	T * temp = new T[arrayCount + 1];
	for(int i = 0; i < arrayCount; i++){
		if(i >= index){
			if(i == index){
				temp[i] = val;
				arrayCount++;
			}
			else{
				temp[i] = start[i-1];
			}
		}
		else{
			temp[i] = start[i];
		}
	}
	T * temp_null = start;
	start = temp;
	temp_null = NULL;
	return;
}
template <typename T>
T arrayList<T>::get(int index){
	T temp;
	if(index > arrayCount || index < 0){
		return temp;
	}
	return start[index];
}
template <typename T>
void arrayList<T>::clear(){
	arrayCount = 0;
	arrayCapacity = 2;
	start = new T[arrayCapacity];
}
template <typename T>
void arrayList<T>::remove(int index){
	if (index >= arrayCount || index < 0){
		return;
	}
	T * temp = new T[arrayCapacity];
	for(int i = 0; i < arrayCount; i++){
		if(i >= index){
			temp[i] = start[i+1];
		}
		else{
			temp[i] = start[i];
		}
	}
	arrayCount--;
	start = temp;
	return;
}
#endif