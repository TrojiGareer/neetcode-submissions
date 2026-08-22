class TimeMap {
    private class Pair {
        int timestamp;
        String value;
        
        public Pair(int timestamp, String value) {
            this.timestamp = timestamp;
            this.value = value;
        }
    }
    private HashMap<String, ArrayList<Pair>> map;

    public TimeMap() {
        map = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if (!map.containsKey(key)) {
            map.put(key, new ArrayList<>());
        }
        map.get(key).add(new Pair(timestamp, value));
    }
    
    public String get(String key, int timestamp) {
        if (!map.containsKey(key)) return "";
        ArrayList<Pair> list = map.get(key);
        int st = 0;
        int dr = list.size() - 1;
        String res = "";
        while (st <= dr) {
            int mid = st + (dr - st) / 2;
            int timp_mid = list.get(mid).timestamp;
            String valoare_mid = list.get(mid).value;
            
            if (timp_mid <= timestamp) {
                res = valoare_mid;
                st = mid + 1;
            }
            else dr = mid - 1;
        }
        return res;
    }
}
