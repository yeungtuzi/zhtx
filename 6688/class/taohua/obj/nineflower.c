//write by lysh
// medicine: nineflower.c
// Jay 3/18/96

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("九花玉露丸", ({"jiuhua wan", "nineflower", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是一粒九花玉露丸。\n");
     		set("no_get",1);
                set("value", 500);
		set("unpawnable",1);
        }
        setup();
}

int do_eat(string arg)
{       
	object me;
        me=this_player();
        if (!id(arg))
                return notify_fail("你要吃什么？\n"); 
	if( me->query("max_force") > 2500  ) {
		me->set("force",(int)me->query("max_force")*2);
		write("你吃了一粒九花玉露丸,只觉得一阵清凉!\n");
       		destruct(this_object());
		return 1;

	}
        
         if ((string)this_player()->query("family/family_name")!="桃花岛")
         {
            me->set("max_force",(int)me->query("max_force")+1);

         write("你吃了一粒九花玉露丸,只觉得一阵清凉!\n");         
          }
          else
         {write("你吃下一粒九花玉露丸，顿时间觉得全身充满了活力 !\n");
            me->set("max_force",(int)me->query("max_force")+2);

          }
       destruct(this_object());
       return 1;
}

