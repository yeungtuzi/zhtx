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
        if (damage_bonus < 0 ) return 0;
        if(random(3)>1)return 0;
        if(random(me->query("force_factor")) > 50) return 0;
        me->add("force",me->query("force_factor"));
        return this_object()->name()+ HIC "从"+HIR"$N"+HIC"手中化作"+HIW"数"+HIG"道"+HIY"旋"+HIM"芒"+HIC"，刺破了天灵万物，直飞向寰宇！\n"NOR;
}




int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query("max_force") < 2000 )
        {
                return notify_fail("你的内功修为太低了，这样的使用神兵小心遭到它的戾气反噬哦！\n"); 
        }
        ob->set("owner", me);
        return ::wield();
}


void owner_is_killed() 
{ 
        object me,ob;
        ob = this_object();
        me = ob->query("owner");
        if(!userp(me)) return 0;
        message("system",HIM"一道绚丽的光芒滑破天际，消失在无尽的虚空之中……"NOR,users() );
        destruct(this_object());
}


int query_autoload()
{
    return query("weapon_prop");
}

