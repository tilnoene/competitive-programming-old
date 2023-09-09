struct setSum {
  multiset<ll> ms;
  ll sum = 0;

  void add(ll value) {
    ms.insert(value);
    sum += value;
  }

  bool rem(ll value) {
    auto it = ms.find(value);

    if (it == ms.end()) {
      return false;
    }

    ms.erase(it);
    sum -= value;

    return true;
  }

  int size() {
    return (int)ms.size();
  }
};

struct bigK {
  setSum gt, lt; // greater then, less then
  ll sum = 0;
  int k;

  bigK(int k) {
    this->k = k;
  }

  void balance() {
    while ((int)gt.size() > k) {
      sum -= *(gt.ms.begin());
      lt.ms.insert(*(gt.ms.begin()));
      gt.ms.erase(gt.ms.begin());
    }

    while ((int)gt.size() > 0 && (int)lt.size() > 0 && (*(prev(lt.ms.end()))) > *(gt.ms.begin())) {
      sum += *(prev(lt.ms.end()));
      sum -= *(gt.ms.begin());

      lt.ms.insert(*(gt.ms.begin()));
      gt.ms.insert(*(prev(lt.ms.end())));

      lt.ms.erase(prev(lt.ms.end()));
      gt.ms.erase(gt.ms.begin());
    }
  }

  void add(ll value) {
    gt.insert(value);
    sum += value;
    balance();
  }

  bool rem(ll value) {
    auto it = gt.ms.find(value);

    if (it != gt.ms.end()) {
      gt.ms.erase(it);
      sum -= value;

      balance();

      return true;
    }

    it = lt.ms.find(value);

    if (it != lt.ms.end()) {
      lt.ms.erase(it);
      sum -= value;

      balance();

      return true;
    }

    return false;
  }
};

/*
  bigK ms(k); // soma dos K maiores elementos do multiset
  
  ms.add(3);
  ms.rem(3);

  cout << ms.sum << '\n';
*/