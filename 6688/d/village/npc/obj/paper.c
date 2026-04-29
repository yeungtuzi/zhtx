#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;
object owner;

void create()
{
        set_name("薄纸",({"paper","zhi"}));
        set_weight(20);
        set("no_get",1);
        set("no_drop","这是杀手信物不能随便丢弃!!!\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "纸");
        }
}

void init()
{
	add_action("do_kill", "kill");
	add_action("do_mask","mask");
	add_action("do_scout","scout");
}

int do_kill(string arg)
{
        object me,obj;

	me=this_player();
	owner=me;
	if( arg==me->query("pkquest/victimid")
		&&!me->query("pkquest/pkdone") )
	{
	        if( environment(me)->query("no_fight") )
        	        return notify_fail("这里不准战斗。\n");
	
        	if(!objectp(obj = present(arg, environment(me))))
                	return notify_fail("这里没有这个人。\n");

	        if( !userp(obj)|| obj->is_corpse() )
        	        return notify_fail("看清楚一点，那并不是人。\n");

        	message_vision(RED"\n突然窜出一个蒙面人对著$n喝道：\n"
		+"「有人化钱买你的人头，休要怪我，你就认命吧！」\n\n"NOR, me, obj);
	
		me->kill_ob(obj);
		obj->kill_ob(me);
		obj->set_temp("killed",1);
		obj->set("pker_name",me->name());
		return 1;
	}
	return 0;
}

int do_mask(string arg)
{
        object me;
	string msg1,msg2;

	me=this_player();

        if (arg == "off")
	{
                me->delete_temp("apply/name");
                me->delete_temp("apply/id");
		me->delete_temp("apply/short");
		me->delete_temp("apply/long");

		me->delete_temp("pker_masked");

                tell_object(me,"你警惕地看了看四周，见四处无人，飞快地把面罩摘了下来。\n");
                return 1;
        }
	if (arg == "on")
	{
		msg1=sprintf("杀手%d号",query("number"));
		msg2=sprintf("shashou%d",query("number"));
		me->set_temp("apply/name",({msg1}) );
		me->set_temp("apply/id",({msg2}) );
		me->set_temp("apply/short",({RED"杀手帮杀手"NOR+" "+msg1+"("+msg2+")"}) );
		me->set_temp("apply/long",({"这是杀手帮的杀手,你最好不要看。\n"}) );

		me->set_temp("pker_masked",1);

	        tell_object(me,"你见四处无人，飞快地戴上一个面罩。\n");
		return 1;
	}
        return notify_fail("蒙面(mask on),摘下面罩(mask off)");
}

int do_scout(string arg)
{
	object where,victim,me;

	me=this_player();
	if ( !(victim=find_player(me->query("pkquest/victimid")) ))
		return notify_fail("对不起，现在找不到你要杀的人。\n");

	where=environment(victim);
	if( !where )
		return notify_fail ("他在虚无飘藐间。\n");

	tell_object(me,victim->query("name")+"("+ victim->query("id")+")"
                       +"现在正在"+where->query("short")+"\n" );
	return 1;
}	

void owner_is_killed() 
{ 
	owner->delete_temp("apply/id");
	owner->delete_temp("apply/name");
	owner->delete_temp("apply/short");
	owner->delete_temp("apply/long");

	owner->delete_temp("pker_masked");

	destruct(this_object());
	return;
}
