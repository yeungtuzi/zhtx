#include <weapon.h>
#include <skill.h>

inherit SWORD;

int a,myclass;
int do_study(string arj);


void create()
{
        set_name("圣火令", ({ "shenghuo ling", "ling" }) );
        set_weight(3000);

    	myclass = 6;

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
        	set("long",
        "这是一块非金非木的令牌，正反两面写满了奇怪的文字，背景是火焰升腾之形。\n");
                set("material", "blacksteal");
                set("value", 0);
                set("rigidity",1000000);
               	set("wield_msg",
			"只听见「飕」地一声，$N的手中已经多了一把黑黝黝的$n。\n");
                set("unequip_msg", "$N随手将$n插入腰间。\n");
        }

	init_sword(20*myclass,SECONDARY);
	
        setup();
}
 void init()
{
	add_action("do_study","study");
}

int do_study(string arg)
{
        object me;

        me = this_player();
	a = me->query_skill("shenghuo-shengong",1);

	if( a < 30 )
	{
		write("以你现在的状态，尚不能领会上面的内容\n");
		return 1;
	}

        if ( (int)me->query_skill("fanwen", 1) < 1)
	{
                write("你不懂梵文，无法领会上面的东西。\n");
		return 1;
	}
   	if( (int)me->query("sen") > 10*myclass+20 )
 	{

        me->add("sen", -10*myclass);

        message_vision("$N正专心研读圣火令上的功夫。\n", me);

	if((int)a*a*a/10 > me->query("combat_exp"))
	{
		write("也许是缺乏实战经验，你对圣火令上的内容总是无法领会。\n");
		return 1;
	}

        if ( (int)me->query_skill("shenghuo-shengong", 1) < 30+20*myclass)
        {
                me->improve_skill("shenghuo-shengong", (int)me->query_skill("fanwen", 1)/5+1);
                write("你对着圣火令琢磨了一回儿，似乎颇有点心得。\n");
                me->set_temp("wall_learned",1);
        }
 }
    else
	{
             write("你现在过于疲倦，无法专心下来研读新知。\n");
        }

        if ( !me->query_temp("wall_learned") )
        {
                write("你对着圣火令琢磨了一回儿，发现上面所载的太过浅显，对你来说已毫无意义了。\n");
        }
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object weap;
	int    wap,wdp;
	string weap_name;

	if(victim == me) return;
	if( objectp(weap = victim->query_temp("weapon")) )
	{

		wap = weight() / 500
			+ query("rigidity")
			+ me->query("str");

		wdp = (int)weap->weight() / 500
			+ (int)weap->query("rigidity")
			+ (int)victim->query("str");


		if(  random(wap) > wdp/2 )
		{
			weap_name = weap->query("name");
			weap->unequip();
			weap->move(me);
			victim->reset_action();
			return "$N将圣火令搭在"+weap->query("name")+"上，大喝一声，$n脸色大变，只感手中的"+weap->query("name")+"一阵剧烈跳动，被$N夹手夺过！\n";		
		}
		if(  random(wap) > wdp/4 )
		{
			return "$N的圣火令搭在"+weap->query("name")+"上，$n只感手中的"+weap->query("name")+"一阵剧烈跳动，几欲把持不住！\n";
		}
			
	}
}


