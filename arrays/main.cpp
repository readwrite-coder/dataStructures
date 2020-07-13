#include <iostream>
#include "arrayList.h"

int main () {

  arrayList my_list;
  my_list.add(1);
  my_list.add(2);
  my_list.add(314);
  my_list.add(44);
  my_list.add(100);
  my_list.add(100);
  //my_list.add(0,69);
  
  for(int i = 0; i < my_list.size(); i++){
    std::cout << my_list.get(i) << ", ";
  }
  std::cout << std::endl;

  my_list.remove(my_list.size());
  my_list.remove(my_list.size()-1); //should delete the last 100, so list is 1, 2, 314, 44, 100
  my_list.remove(my_list.size()-3); //should delete 314, now list is 1, 2, 44, 100

  for(int i = 0; i < my_list.size(); i++){
    std::cout << my_list.get(i) << ", ";
  }
  std::cout << std::endl;

  if(my_list.isEmpty()){
    std::cout << "list is empty" << std::endl;
  }
  else{
    std::cout << "list is not empty, size is: " << my_list.size() << std::endl;
  }
  std::cout<< my_list.get(0) << std::endl;
  my_list.clear();
  if(my_list.isEmpty()){
    std::cout << "list is empty" << std::endl;
  }
  else{
    std::cout << "list is not empty, size is: " << my_list.size() << std::endl;
  }

  int x = 10;
  int subA1 [10] = {1,2,3,4,5,6,7,8,9,10};
  int subA2 [10] = {1,2,3,4,5,6,7,8,9,10};
  int subA3 [10] = {1,2,3,4,5,6,7,8,9,10};
  int array [3][10] = 
  {
  {1,2,3,4,5,6,7,8,9,10},
  {1,2,3,4,5,6,7,8,9,10},
  {1,2,3,4,5,6,7,8,9,10}
  };  

  //not allowed to declare the array of arrays as {subA1, subA2, subA3}
  for(int i = 0; i < 3; i++){
     
     for(int j = 0; j < 10; j++){
     	//std::cout << array[i][j] <<" ";
     }
     //std::cout << std::endl;
  }

  //int dyanamic_array [][]; not allowed;
  int ** dyanamic_array; 
  dyanamic_array = new int*[3];
  for (int i = 0; i < 3; i ++){
  	dyanamic_array[i] = new int[10];
  	dyanamic_array[i] = subA1;
  }

  for(int i = 0; i < 3; i ++){
  	for(int j = i; j < 10; j ++){
  		//std::cout << dyanamic_array[i][j] << " " ;
  	}
  	//std::cout << std::endl;
  }

}
