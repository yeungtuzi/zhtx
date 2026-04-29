// yunu-xinfa 古墓 玉女心法
// create by dingdang
inherit FORCE;
int valid_enable(string usage)
{
        return usage == "force";
}
int valid_learn(object me)
{
        int i, nf, ns;
        
        nf = (int)me->query_skill("force", 1);
        
        ns = (int)me->query("guilty");                                    
        
        if ( nf < 10)
                return notify_fail("你的基本内功火候还不够，无法领会玉女心法\n");
        
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("玉女心法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"yunu-xinfa/" + func;
}
int query_faith_req(int skill) {
       return 10;

}
string query_force_type() {	return "道家内功"; }
