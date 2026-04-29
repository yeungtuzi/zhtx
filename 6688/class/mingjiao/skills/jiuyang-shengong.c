inherit FORCE;


string *absorb_msg = ({
        "$N身体虚转，双手微划，无坚不摧的九阳神功澎湃而出。\n",

        "$N施展出九阳神功，浑身肌肤坚如寒铁。\n",

        "$N身型微展，九阳神功充斥了丈许空间。\n",

        "$N心神一动，他强由他强，清风拂山岗，真气护满全身。\n", 

        "$N心神一动，他横由他横，明月照大江，真气护满全身。\n",

        "$N心中默念，他自狠来他自恶，我自胸中一口气。\n",
        });


int valid_enable(string usage)
{
	if(usage == "force")
		return 1;
/*
	if(usage == "iron-cloth")
		if( this_player()->query_skill_mapped("force") == "jiuyang-shengong" )
			return 1;
		else
		{	
			tell_object(this_player(),"九阳神功必须以内功作为根基才能够发挥护体的效用！\n");
			return 0;
		}
*/
	return 0;
}

int bounce_ratio()
{
        return 60;
}

int practice_skill(object me)
{
        return notify_fail("九阳神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}


int valid_learn(object me)
{
	int nf;
	nf = (int)me->query_skill("force", 1);

	if ( nf < 100)
		return notify_fail("你的基本内功火候还不够，无法领会九阳神功。\n");

	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}

varargs string  query_absorb_msg(string limb)
{
       return absorb_msg[random(sizeof(absorb_msg))];
}

string query_force_type() {

	return "佛家内功";
}

int query_faith_req(int skill) {
	return 10+skill*12;

}
