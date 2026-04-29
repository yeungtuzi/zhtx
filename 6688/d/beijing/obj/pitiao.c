// pitiao.c
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(WHT"批条"NOR, ({ "pitiao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("materials","cloth");
		set("long", "一张空白的批条，下边有个鲜红的“御膳监”的小印。你可以填写(apply)它。\n");
		set("value","5");
	}
}
void init()
{         add_action("do_write","apply");
}
void do_write(object who)
{         object ob;
	  ob=new(__DIR__"pitiao2");
	  message_vision("$N大笔一挥，在批条上写下：“奉命取某某若干，见字放行！”\n",who);
	  ob->move(who);
	  destruct(this_object());
}
          
