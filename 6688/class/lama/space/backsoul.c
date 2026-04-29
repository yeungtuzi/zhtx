// /daemon/class/lama/space/backsoul.c

#include <ansi.h>
#include <login.h>

inherit F_CLEAN_UP;
inherit SSERVER;

int conjure(object me, object target)
{
        if( wizardp(me) )return notify_fail("巫师限制使用此法术!\n");
	if( me->is_fighting() ) return notify_fail("拜托,先打完这架再说!\n");
	write("你要以自己的生命换回谁的灵魂?");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
        object ob;
	int myexp, yourexp, i;
	string *sk;
	mapping skills;
//	mapping learned;
//	mapping skill_map;
//	mapping skill_prepare;

        if( !name || name=="" ) {
                write("中止施法。\n");
                return;
        }

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);

	if( !ob ) {write("你要召回谁的灵魂?\n"); return;}
	if( ob==me) {write("对自己用无效.\n"); return;}
	if(me->is_ghost()) {write("你自己也死了,还召个头.\n"); return;}
	if(!ob->is_ghost()) {write("召魂术只能用于鬼魂.\n"); return;}
	if(!userp(ob)) {write("不值得这样做.\n"); return;}
	myexp=me->query("combat_exp");
	yourexp=ob->query("combat_exp");
	if(myexp<yourexp) {
		write("无法对"+ob->query("name")+"施展回魂术.\n");
		return;
	}
	tell_object(me,"你决定牺牲自己,召回"+ob->query("name")+"的灵魂.\n");
	tell_object(ob,me->query("name")+"决定牺牲自己,召回你的灵魂.\n");
	yourexp+=myexp/10;
	skills=me->query_skills();
	sk=keys(skills);
	for(i=0; i<sizeof(sk); i++) {
		me->delete_skill(sk[i]);
	}
	//grin, learned removed at same time
//	learned=me->query_learned();
//	skill_map=me->query_skill_map();
//	skill_prepare=me->query_skill_prepare();
//	here is a bug, doesn't delete (though not shown) the skill_map

	ob->reincarnate();
	ob->move(REVIVE_ROOM);
        message("vision",
                "你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
                "很久了，只是你一直没发觉。\n", environment(ob), ob);
	ob->set("combat_exp", yourexp);
	return;
}
