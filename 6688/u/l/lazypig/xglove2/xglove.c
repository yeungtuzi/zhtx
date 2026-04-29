#include <weapon.h>
#include <ansi.h>

// inherit UNARM;
//inherit UND;
#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_und(int damage, int flag)
{
        string usage;

        if( clonep(this_object()) ) return;

        set("weapon_prop/damage", damage);
        set("flag", (int)flag | EDGED);
        set("flag", (int)flag | EDGED);
        set("skill_type","unarmed");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
        }
}


void init()
{
  add_action("do_decide","decide");
}

int do_decide(string arg)
{
   object me;
   object obj;
   me=this_player();
if (arg!="finger" && arg!="hand" && arg!="strike" && arg!="cuff" && arg!="claw" && arg!="unarmed") return notify_fail("你准备用鬼手催动什么功夫?\n");
{
      if(arg=="finger") {obj=new(__DIR__"f_glove");obj->move(me);
write("你决定将鬼手定义为指法武器。\n");}
      if(arg=="strike") {obj=new(__DIR__"s_glove");obj->move(me);
write("你决定将鬼手定义为掌法武器。\n");}
      if(arg=="hand") {obj=new(__DIR__"h_glove");obj->move(me);
write("你决定将鬼手定义为手法武器。\n");}
      if(arg=="cuff") {obj=new(__DIR__"cu_glove");obj->move(me);
write("你决定将鬼手定义为拳法武器。\n");}
      if(arg=="claw") {obj=new(__DIR__"cl_glove");obj->move(me);
write("你决定将鬼手定义为爪法武器。\n");}
      if(arg=="unarmed") {obj=new(__DIR__"unglove");obj->move(me);
write("你决定将鬼手定义为普通空手武器。\n");}
    destruct(this_object());
   }
   return 1;
} 

void create()
{
        set_name(HIB"鬼 手"NOR, ({ "lighting glove", "glove" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "可以定义(decide)为不同种类的鬼手，杀人无数，无坚不摧! \n");
                set("value", 0);
                set("material", "crimson gold");
                set("rigidity", 99);
        }
        init_und(199);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
   me->add("force",me->query("force_factor"));
}

int query_autoload()
{
    return query("weapon_prop");
}

