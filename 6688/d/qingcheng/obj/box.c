/* box.c */
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("铁箱", ({ "box" }) );
	set_weight(2000);
	set("value",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个小铁箱，因为久沉井底，已经被泡得全是铁锈了。\n"+
			    "隐隐可以看见箱子的正面有两个按钮(button)，一个是\n"+
			    "红色的，一个是蓝色的，可能是什么机关吧。你要不要\n"+
			    "压(press red or blue)一压其中的一个按钮试试看?\n"
				
				);
	}
	setup();
} 
void init()
{      add_action("do_press","press");
}
void effect(object me,object who)
{       int i;
	object badbox,pixie;
	me = this_object();
	who = this_player();
	if((int)who->query("marks/pixie2")==0)
	message_vision("铁箱响了几下，接着什么动静也没有了.可能内部机关已经给锈住了。"
	+MAG"^_*\n"NOR,who);
	else {
	badbox=new(__DIR__"badbox");
	pixie=new(__DIR__"jiasha");
	message_vision("只听到 '蓬' 的一声，铁箱向$N射出一大把小银针!!!\n"+
		RED"$N连忙向一边躲开，但已经晚了!一部分银针射中了$N!!!\n"NOR,who);
	who->set_temp("marks/pixie2",0);
	who->set("marks/pixie3",1);
	  i =  (int)who->query("eff_kee");
	who->set("eff_kee",i-250-random(450));
	who->set("kee",i-350-random(450));
	if(who->query("kee")>0)
	{
	badbox->move(who);
	pixie->move(who); 
	destruct(this_object());
	}
	}
}

int do_press(string arg)
{       object me,who;
	me = this_object();
	who = this_player();
	if( who->is_busy() ) 
		return notify_fail("你现在没有空！\n");

	if(arg=="red")  
	{       message_vision("$N用力压了一下"+RED"红色按钮......\n"NOR,who);
		call_out("effect",1);
		return 1;}
	else if(arg=="blue") {
	      message_vision("$N用力压了一下"+HIB"蓝色按钮......\n"NOR,who);
		call_out("effect",1);
		who->start_busy(4);
		return 1;}
	else 
	return notify_fail("你要压哪个按钮?\n");
}
