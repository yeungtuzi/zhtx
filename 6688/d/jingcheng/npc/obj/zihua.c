//write by lysh
//字画
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("字画",({"zi hua","zi","hua"}));
    set_weight(10);
     if (clonep() )
      set_default_object(__FILE__);
    else {
      set("long","一幅字画\n");
      set("value",1000);
      set("unit","幅");
      }
}
