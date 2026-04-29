//sword.c
//made by kiss
inherit F_AUTOLOAD;
#include <ansi.h>
#include <weapon.h>
#include <skill.h>
inherit SWORD;

int do_yanjiu(string arg);
int do_search(string arg);

void create()
{
 set_name(HIW"清风剑"NOR,({"chang jian","jian"}));
 set_weight(8000);
 set("no_drop",HIW"这是你师傅给你的剑，怎么可以乱丢 !\n"NOR);
 set("no_give",HIW"师傅给的剑，怎么能随便给别人!\n"NOR);
 set("no_sell",1);
 //set("no_get",1);
 if(clonep())
   set_default_object(__FILE__);
 else {
   set("unit","柄");
   set("value",5000);
   set("long",@LONG
这是一吧看似寻常的长剑，但拿在手里却很合手。剑的表面与
别的长剑没有什么差别，但在剑柄上却刻有一排小字: 
               重阳赠与爱徒
LONG
    );
   set("material","steel");
   set("wield_msg","$N[唰]的一声抽出一柄$n握在手中. \n");
   set("unwield_msg","$N将手中的$n插回剑鞘. \n");
  }
   init_sword(44);
   setup();
  }

int query_autoload() { return 1; }

void init()
{  add_action("do_search","search");
   add_action("do_yanjiu","yanjiu");
}

int do_search(string arg)
{
 object me;
 me=this_player();
 if(arg!="chang jian")
 {
  write("你要找什么？\n");
  return 1;
  }
  me->set_temp("have_search",1);
  write("你仔细地看了看这把剑，忽然发现在剑锋上居然刻着一些密密麻麻\n");
  write("的小字，原来是全真剑法的秘诀，你乐得差点晕倒了!\n");
  return 1;
 }

int do_yanjiu(string arg)
{
 object me;
 me=this_player();
  if(!me->query_temp("have_search"))
  {
  write("你要干什么?\n");
  return 1;
   }
  if(me->query("family/family_name")!="全真派")
   {
   write("偷学别人门派的东西不好吧!\n");
   return 1;
   }
 if(me->query_skill("quanzhen-jian",1)>120)
  {
  write("你对着剑琢磨了一回儿，发现上面所载的太过浅显，对你来说已毫无意义\n");
  return 1;
  }
  if(me->query("sen")<40)
  {
  write("你太累了，休息一下吧！\n");
   return 1;
  }
        
  if(arg!="chang jian"&&arg!="jian") return 1;
  me->improve_skill("quanzhen-jian", ((int)me->query("int")/5)+random(4));
  write("你对着清风剑琢磨了一回儿，似乎颇有点心得。\n");
  me->add("sen",-30-random(6));
  return 1;
 }

          
