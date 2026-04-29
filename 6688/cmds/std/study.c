// study.c

#include <skill.h>
#define ALL_COST -10000
#define ONE_COST -1000

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object where = environment(me);
	object ob;
	string zhao_name;
	mapping skill;
	int my_skill, cost,point,times=0;

	if(!arg) return notify_fail("请用 help study 查看其用法。\n");

	if(sscanf(arg,"%s with all",arg)==1)  point=ALL_COST;
	else if(sscanf(arg,"%s with %d",arg,point)==2)
	{
		if(point <= 0 ) return notify_fail("你不是开玩笑吧.\n");
		if(point > me->query("sen") ) return notify_fail("你没有这么多神。\n");
	}
	else point=ONE_COST;

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if(!arg || !objectp(ob = present(arg, me)) )
		return notify_fail("你要读什么？\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("你无法从这样东西学到任何东西。\n");

	if( !me->query_skill("literate", 1) )
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

                message_vision( me->name() + "正专心地研读" + ob->name()+ "。\n", me);

	if( (int)me->query("combat_exp") < skill["exp_required"] ) {
		printf("你的实战经验不足，再怎么读也没用。\n");
		return 1;
	}
	
	notify_fail("以你目前的能力，还没有办法学这个技能。\n");
	// require base skill 
	if ( me->query_skill(skill["name"],1) < skill["base_skill"] ) 
		return 0;
	if( !SKILL_D(skill["name"])->check_base_skill(me,skill["name"])) return 0;
	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
		printf("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
		return 1;
	}

	if( !me->query_skill(skill["name"], 1) ) me->set_skill(skill["name"], 0);

	my_skill = me->query_skill(skill["name"], 1);

	cost = skill["sen_cost"] + skill["sen_cost"] 
* (skill["difficulty"] - (int)me->query("int") - (int)me->query_skill("literate")/10)/20;
	if (cost < 10) cost = 10; // minimum cost

	if(point == ONE_COST){
		if(me->query("sen") >= cost) times=1;
	}
	else if(point==ALL_COST){
		times = me->query("sen")/cost;
		cost *= times;
	}
	else{
		times = point/cost;
		cost *= times;
	}

	if( times>0 ) {
		if( (string)SKILL_D(skill["name"])->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			printf("也许是缺乏实战经验，你对%s上面所说的东西总是无法领会。\n", ob->name());
		} else {
			if(!(int)me->query("env/message_brief")){
				if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
					printf("你研读有关%s的技巧，对「%s」这一招似乎有些心得。\n", 
						to_chinese(skill["name"]), zhao_name);
				else
					printf("你研读有关%s的技巧，似乎有点心得。\n", to_chinese(skill["name"]));
			}
			me->improve_skill(skill["name"], times*((int)me->query_skill("literate", 1)/5+1) );
			me->receive_damage("sen", cost );
		}
	} else {
//		cost = me->query("sen");
		printf("你现在过于疲倦，无法专心下来研读新知。\n");
	}

	return 1;
}

int help(object me)
{
   write( @HELP
指令格式:

study|du <物品名称>                   : 逐次地读。
study|du <物品名称> with <神的点数>   : 指定需耗神的点数。
study|du <物品名称> with all          : 耗全部的神。

这个指令使你可以通过阅读秘笈或其他物品自学某些技巧,
但前提是: 你不能是个『文盲』。

see also : learn
HELP
   );
   return 1;
}
