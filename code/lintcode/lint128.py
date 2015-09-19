
class Solution:
    """
    @param key: A String you should hash
    @param HASH_SIZE: An integer
    @return an integer
    """
    def hashCode(self, key, HASH_SIZE):
        # write your code here
        res = 0
        w = 1
        for i in xrange(len(key)-1, -1, -1):
        	res  = (res + ord(key[i]) * w) % HASH_SIZE
        	w = (w * 33) % HASH_SIZE
        return res;


if __name__=="__main__":
	print Solution().hashCode("abcd", 100)
