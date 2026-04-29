// daguanming.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        int lvl;
        
        lvl = (int)me->query_skill("daguanming", 1);
        
        if( (int)me->query("shen") > 100 )
        return notify_fail("你的正气太重，无法修炼大光明心法。\n");
//        if( me->query("family/family_name") != "日月神教" )
//        return notify_fail("你并非日月神教中人，学着没用的功夫干嘛！\n");
                
//        if(me->query("gender") == "无性" && lvl > 39)
//                return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之气，无法领会里面的阴阳变化之道。\n");
           
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("大光明心法只能靠学习来提高。\n");
}

void skill_improved(object me)
{
	int cor,level;

	cor = me->query("spi"); //日月教非常需要灵性，武功多
	level = me->query_skill("daguanming",1);
	
	if( cor < level/4 )
        if( cor < level/4  )
	{
		tell_object(me,"你修习神教宝典，仿佛听到心中一个声音说：教主宝训，牢记在心，攻无不克，战无不胜！\n");
		me->add("spi",1);
	}
	if( me->query("bellicosity") < 10000 )
		me->add("bellicosity",500);
}
