//write by lysh
//请帖
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("请帖",({"qing tie","qing","tie"}));
    set_weight(1);	
     if (clonep() )
      set_default_object(__FILE__);
    else {
      set("long","一张请帖\n");
      set("value",1);
      set("unit","张");
      }
}
