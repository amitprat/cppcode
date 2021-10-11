# Implement Bitset datastructure

*Given an input stream of boolean values, design a data structure that can support following modules in optimal time-
i) setTrue(index)
ii) setFalse(index)
iii) setAllTrue()
iv) setAllFalse()
v) getIndex(index)*


We can record the timestamp / operation number of each of the operation. With that said we will store the last time setAllTrue was executed and last time setAllFalse was executed. Also we store the last time particular index was updated. We can compare the time to get the value at that index.

```cpp
vector<bool> arr(n);
vector<int> lastUpdatedAt;
int op = 0;
int lastSetTrue, lastSetFalse;

void setTrue(int i) {
    op++;
	arr[i] = true;
	lastUpdatedAt[i] = op;
}

void setFalse(int i) {
    op++;
	arr[i] = false;
	lastUpdatedAt[i] = op;
}

void setAllTrue() {
	op++;
	lastSetTrue = op;
}
void setAllFalse() {
	op++;
	lastSetFalse = op;
}


bool get(int i) {

    if(lastUpdatedAt[i] < lastSetTrue && lastUpdatedAt[i] < lastSetFalse) {
        return lastSetTrue > lastSetFalse;
    }
    if(lastUpdatedAt[i] < lastSetTrue) {
        return true;
    }
    if(lastUpdatedAt[i] < lastSetFalse) {
        return false;
    }
    return arr[i];
}
```

Assume 32 bit integer

```cpp
bit_vector = vector<int>;

void setTrue(index) {
	int remainder = index % 32;
	bit_vector[index/32] |= 1 << remainder; 
}

void setFalse(index) {
	int remainder = index % 32;
	bit_vector[index/32] &= ~(1 << remainder); 
}

void setAllTrue() {
	for (int& i : bit_vector) {
		i |= 0xFFFF;
	}
}

void setAllFalse() {
	for (int& i : bit_vector) {
		i &= 0;
	}
}

bool getIndex(index) {
	int remainder = index % 32;
	return (bit_vector[index/32] >> remainder) & 1;  
}
```
