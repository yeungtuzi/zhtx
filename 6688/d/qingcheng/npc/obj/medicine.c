/* medicine.c*/
#include <ansi.h>
inherit ITEM;

int do_apply(string);
void init();

void init()
{
        
                                              
        add_action("do_apply", "apply");
}

void create()
{
        set_name( "伤药" ,({ "medicine"}));
        set_weight(50);
        if (clonep())


                set_default_object(__FILE__);


        else {
                set("unit", "份");
                set("long", 
"这是一份伤药,你如果受伤了,可用(apply)来敷上它。\n");
                set("value", 2000);
        }

        setup();
}

int do_apply(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要敷上什么？\n");
         
      else if((int)me->query("eff_kee")==(int)me->query("max_kee"))
         message_vision("你没有受伤啊!");
       else if(((int)me->query("eff_kee")+50)>(int)me->query("max_kee"))
        me->set("eff_kee", (int)me->query("max_kee"));
       else me->set("eff_kee",(int)me->query("eff_kee")+50);       
        message_vision(
 "$N你敷上伤药,脸色好看多了.\n",me);

        destruct(this_object());
        return 1;
          }
