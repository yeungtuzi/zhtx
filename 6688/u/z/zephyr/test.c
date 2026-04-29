inherit ITEM;
string chstring(string,int);
#include <ansi.h>

int kar_seed;

void create()
{
	set_name("木锯", ({ "mu ju", "saw"}) );
	set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long",@DESC
一把银光闪闪锋利无比的木锯。可以用它来锯倒大树(chop)。
DESC
		);

        	set("unpawnable", 1);
			set("location","0");
	}
	setup();  
}

void init()
{
	add_action("do_chop","chop");          
}


int do_chop()
{
	object env, wood, saw, me=this_player(),room;
	int i;
	string room_long;
	room=environment(this_object());
	room=environment(room);
	room_long=room->query("long");
	
	if( strsrch(room_long, "树") >=0 || strsrch(room_long, "木") >=0 ) 
	{
		message_vision(HIY"$N挽挽袖子，手持锯子，嘿哟嘿哟的冲着路边的大树锯了起来，也不怕被官府抓起来.\n"NOR,me);
	}
	else return notify_fail("这周围好像没有什么树木可以锯吧？\n");
	if( me->query("kee") < 100 )
		return notify_fail("你太累啦，歇一歇吧！\n");
	me->receive_damage("kee",90);

	env = environment(me);
	if( base_name(env) == this_object()->query("location") )
	{	
		if (random(100)>98)
		{
			wood = new(__DIR__"wood");
			wood->move(me);
			saw = this_object();
			message_vision(HIG"吱嘎嘎一阵巨响之后，$N终于锯倒了一棵大树，收好锯子，$N弯下腰去，气沉丹田，一声起－－－把树木抗在了肩上。\n"NOR,me);
			message_vision(HIG"$N低头看锯子时，发现锯齿已经都被磨得东倒西歪，眼见得不能用了。\n"NOR,me);
			destruct(saw);
			return 1;
		}
		else message_vision(HIG"$N嘿哟嘿哟地锯了半天，累个半死，却连块树皮都没锯掉。\n"NOR,me);
		return 1;
	}
	else
	{
		if (random(100)>98)
		{
			wood = new(__DIR__"fakewood");
			wood->move(me);
			tell_object(me,HIG"吱嘎嘎一阵巨响之后，$N终于锯倒了一棵大树，收好锯子，$N弯下腰去，气沉丹田，一声起－－－把树木抗在了肩上。\n"NOR);
			return 1;
		}
		else message_vision(HIG"$N嘿哟嘿哟地锯啊锯...\n"NOR,me);
	}
	return 1;
}
