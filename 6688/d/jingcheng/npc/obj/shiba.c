//write by lysh
//十八学士(假的)
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"十八学士"NOR,({"shi ba xue shi","shi"}));
    set_weight(10);
     if (clonep() )
      set_default_object(__FILE__);
    else {
      set("long","一株十八学士\n");
      set("value",2000);
      set("unit","株");
      }
}
