//feng wang mi.c
//made by kiss

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void init()
{
   add_action("do_eat","eat");
 }
 
void create()
{
  set_name("蜂王蜜",({"feng wang mi","mi"}));
  set_weight(100);
  if( clonep() )
      set_default_object(__FILE__);
   else 
  {
    set("unit","瓶");
    set("long","这是一瓶新鲜的蜂王蜜.\n");
    set("value",1000);
    setup();
  }
}

int do_eat(string arg)
 {  
  if(!id(arg))
   return notify_fail("你要吃什么？\n");
if( this_player()->query("max_force") < 3500 ) 
   this_player()->add("max_force",random(2)+1);
if( this_player()->query("max_atman") < 500) 
   this_player()->add("max_atman",1);
  this_player()->add("water",50); 
  message_vision("$N喝下一瓶蜂王蜜，只感觉全身好象脱胎换股，精神为之一振!\n",this_player());
    destruct(this_object());
   return 1;
  }
