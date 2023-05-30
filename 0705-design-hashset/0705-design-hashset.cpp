class MyHashSet {
private:
	std::vector<bool> hashset; // hashset[i] = true if i is in set

public:
	/**
	 * Instantiates an empty hash set
	 */
	MyHashSet() {
		this->hashset = std::vector<bool>(1e6 + 1, false);
	}

	/**
	 * Adds a key to the hash set
	 *
	 * @param key key to add
	 */
	void add(int key) {
		this->hashset[key] = true;
	}

	/**
	 * Removes a key from the hash set
	 *
	 * @param key key to remove
	 */
	void remove(int key) {
		this->hashset[key] = false;
	}

	/**
	 * Check if hash set contains a specific key
	 *
	 * @param key key to check for
	 *
	 * @return true if key is in hash set, false otherwise
	 */
	bool contains(int key) {
		return this->hashset[key];
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */