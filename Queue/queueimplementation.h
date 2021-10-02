namespace normal {
	class queue {
	public:
		queue() : _front{ 0 }, _back{ -1 }{ };
		int front() {
			if (_front > _back) throw("error");
			return arr[_front];
		}
		int pop() {
			if (_front > _back) throw("Error");
			_front++;
			if (_front > _back) {
				_front = 0;
				_back = -1;
			}
		}
		bool empty() {
			if (_front <= _back) return 0;
			return 1;
		}
		int push(int i) {
			_back++;
			arr[_back] = i;
			return i;
		}

	private:
		int* arr = new int[100];
		int _front, _back;
	};
}

namespace link {
	template<typename t>
	class node {
	public:
		t val;
		node<t>* next;
		node(t i = -1) :next{ nullptr }, val{ i }{};
	};
	template<typename t>
	class queue {
	public:
		queue() :_front{ nullptr }, _back{ nullptr }{};
		t push(t i);
		t pop();
		bool empty();
		t front();


	private:
		node<t>* _front;
		node<t>* _back;
	};

	template<typename t>
	t queue<t>::push(t i) {
		node<t>* temp = new node<t>(i);
		if (_front == nullptr) _front = temp;
		if(_back!=nullptr)_back->next = temp;
		_back = temp;
		return i;
	}
	template<typename t>
	t queue<t>::pop() {
		if (_front == nullptr) throw "Under flow";
		t val = _front->val;
		_front = _front->next;
		return val;
	}
	template<typename t>
	bool queue<t>::empty() {
		if (_front == nullptr) return 1;
		return 0;
	}
	template<typename t>
	t queue<t>::front() {
		if (_front == nullptr) throw "Error";
		return _front->val;
	}


}