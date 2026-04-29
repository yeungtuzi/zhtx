//sword.c
//made by kiss
inherit F_AUTOLOAD;
#include <ansi.h>
#include <weapon.h>
#include <skill.h>
inherit SWORD;

void create()
{
 set_name(CYN"青锋剑"NOR,({"qingfeng jian","jian","sword"}));
 set_weight(8000);
 set("no_drop",HIW"这是你师傅给你的剑，怎么可以乱丢 !\n"NOR);
 set("no_give",HIW"师傅给的剑，怎么能随便给别人!\n"NOR);
 set("no_sell",1);
 if(clonep())
   set_default_object(__FILE__);
 else {
   set("unit","柄");
   set("value",5000);
   set("long",@LONG
这是一吧看似寻常的长剑，但拿在手里却很合手。剑的表面与
别的长剑没有什么差别，但在剑柄上却刻有一排小字: 
               风清扬赠于爱徒
LONG
    );
   set("material","steel");
   set("wield_msg","$N[唰]的一声抽出一柄$n握在手中. \n");
   set("unwield_msg","$N将手中的$n插回剑鞘. \n");
  }
   init_sword(50);
   setup();
  }

int query_autoload() { return 1; }

