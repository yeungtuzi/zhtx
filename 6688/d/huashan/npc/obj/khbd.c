//葵花宝典残本
//khbd.c
inherit ITEM;
#include <ansi.h>
int do_tear(string var);
void create()
{
        set_name( "破书", ({ "book",}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一册很破旧的小册子，封皮又黄又破。\n");
                set("value", 0);
                set("material", "paper");
                /*set("skill", ([
                        "name": "purple",       // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost": 20,        // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    50,     // the maximum level you can learn
                ]) );*/
        }
        
}
 
void init()
{
	add_action("do_tear","tear");
	
}

int do_tear(string arg)
{
	if(!arg||arg=="")
	  return notify_fail("你要撕什么？\n");
	if(arg=="book")
	{
	message_vision("$N小心的撕开了小册子的封皮，从里面找出两张纸，赫然就是传说中的葵花宝典。\n",this_player());
	set_name( "「葵花宝典残本」", ({ "kuihua baodian","book",}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一册很破旧的小册子，封皮又黄又破。\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name": "kuihua-shengong",       // name of the skill
                        "exp_required": 10000,      // minimum combat experience required
                        "jing_cost": 20,        // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    70,     // the maximum level you can learn
                        "base_skill": 30,
                ]) );
        }
	   return 1;	
	}  
	return notify_fail("你要撕什么？\n");
}