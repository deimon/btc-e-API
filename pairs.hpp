#ifndef PAIRS_HPP
#define PAIRS_HPP

#include <string>

using url = std::string;

namespace btc_e {

class pair {
public:
    pair() {}
    pair(const url& u, unsigned int decimal_places = 3) : _url(_base_url), name_(u), _decimal_places(decimal_places) {}
    virtual ~pair() {}
    
    virtual url fee() const {
        return _url + "fee/" + name_;
    }
    virtual url ticker() const {
        return _url + "ticker/" + name_;
    }
    
    virtual url trades() const {
        return _url + "trades/" + name_;
    }
    
    virtual url depth() const {
        return _url + "depth/" + name_;
    }
    
    virtual std::string name() const {
        return name_;
    }

    unsigned int GetDecimalPlaces() const { return _decimal_places; }
    
private:
    static url _base_url;
    url _url;
    std::string name_;
    unsigned int _decimal_places;
};
url pair::_base_url = "https://wex.nz/api/3/";

class btc_usd: public pair {
public:
    btc_usd(): pair("btc_usd", 3) {}
};

class btc_eur: public pair {
public:
    btc_eur(): pair("btc_eur", 5) {}
};

class btc_rur: public pair {
public:
    btc_rur(): pair("btc_rur", 5) {}
};

class ltc_btc: public pair {
public:
    ltc_btc(): pair("ltc_btc", 5) {}
};

class ltc_usd: public pair {
public:
    ltc_usd(): pair("ltc_usd", 6) {}
};

class ltc_rur: public pair {
public:
    ltc_rur(): pair("ltc_rur", 5) {}
};

class nmc_btc: public pair {
public:
    nmc_btc(): pair("nmc_btc", 5) {}
};

class usd_rur: public pair {
public:
    usd_rur(): pair("usd_rur", 5) {}
};

class eur_usd: public pair {
public:
    eur_usd(): pair("eur_usd", 5) {}
};

class dsh_usd : public pair {
public:
  dsh_usd() : pair("dsh_usd", 5) {}
};

class dsh_btc : public pair {
public:
  dsh_btc() : pair("dsh_btc", 5) {}
};

class eth_usd : public pair {
public:
  eth_usd() : pair("eth_usd", 5) {}
};

class eth_btc : public pair {
public:
  eth_btc() : pair("eth_btc", 5) {}
};

class bch_usd : public pair {
public:
  bch_usd() : pair("bch_usd", 3) {}
};

class bch_btc : public pair {
public:
  bch_btc() : pair("bch_btc", 4) {}
};

enum class type {
    sell,
    buy
};

} // ns btc_e

#endif