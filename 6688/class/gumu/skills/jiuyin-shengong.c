//by masterall
//2003.7.19

inherit FORCE;

 string *absorb_msg = ({
        "$n身体虚转，双手微划，无坚不摧的九阴神功澎湃而出。\n",

        "$n施展出九阴神功，浑身肌肤坚如寒铁。\n",

        "$n身型微展，九阴神功充斥了丈许空间。\n",

        "$n心神一动，他强由他强，清风拂山岗，真气护满全身。\n", 

        "$n心神一动，他横由他横，明月照大江，真气护满全身。\n",

        "$n心中默念，他自狠来他自恶，我自胸中一口气。\n",
        });

int valid_enable(string usage)
{
return usage == "force" || usage == "iron-cloth";
}

int valid_learn(object me)
{
        int i, nf,nj;
        nf = (int)me->query_skill("yunu-xinfa", 1);
        nj = (int)me->query_skill("jiuyin-shengong", 1);

        if ( nf < nj +20 && nj < 220 )
                return notify_fail("你的玉女心法火候还不够，无法领会九阴神功之境界，强行修炼会走火入魔的。\n");

        return 1;
}

int bounce_ratio()
{
        return 25;
}
int effective_level() {
//    if( this_player()->query_skill_mapped("force") != "jiuyin-shengong" )
           return 40;
//         return 10; 
}

int practice_skill(object me)
{
        return notify_fail("九阴神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"jiuyin-shengong/" + func;
}
string query_force_type() {

        return "道家内功";
}


query_absorb_msg(string limb)
{
       return absorb_msg[random(sizeof(absorb_msg))];
}

