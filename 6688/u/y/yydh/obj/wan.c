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
          if ((int) me->query("force") < (int)me->query("max_force"))
              {
                me->set("force",0);
                }
           else
                 {
                  me->set("force",(int)me->query("max_force")/4); 
                  } 
          write("你吃了一粒九花玉露丸,只觉得一阵清凉!\n");
       destruct(this_object());
       return 1;
}

