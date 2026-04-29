//write by lysh
//野花�)
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("野花",({"ye hua","ye","hua"}));
    set_weight(10);
     if (clonep() )
      set_default_object(__FILE__);
    else {
      set("long","一朵野花\n");
      set("value",0);
      set("unit","朵");
      }
}
