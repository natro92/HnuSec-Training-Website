import time
def random():
    a = 50533690
    b = 229028
    mod = (a ^ b) * (a << (b >> 14)) % 1e9
    return int((((time.time()*(a^(int(time.time())>>1)*a)))+b)%mod)