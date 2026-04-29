// malatang.c 麻辣烫
#include <ansi.h>

inherit ITEM;    
inherit F_FOOD;

int do_eat(string);
void init();

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR "麻辣烫" NOR, ({"mala tang","tang"}));
        set_weight(20);
        if (clonep())
		set_default_object(__FILE__);
	else
	{
        	set("unit", "份");
        	set("long", 
			"这是一份热气腾腾的麻辣烫，还没有吃你就能感觉到它的热力和刺激！\n");
 
		set("value", 100);
        }
	
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");

if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
                return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");
	
	me->add("food",10);
	if(me->query("water")>5) me->add("water",-5);	
        message_vision(HIM
 "$N吃下一份热气腾腾的麻辣烫，豆大的汗珠从额头流下，好爽啊! \n"NOR,me);

        destruct(this_object());
        return 1;
}
