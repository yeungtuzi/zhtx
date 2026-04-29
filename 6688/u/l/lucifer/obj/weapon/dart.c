// masterall
// 断魂砂

#include <weapon.h>
#include <ansi.h>

inherit THROWING;
inherit F_AUTOLOAD;

int query_autoload()
{
        return query("weapon_prop");
}

void attack_ob(object me,object victim,int ap);

void create()
{
        set_name(HIB"断魂砂"NOR, ({ "duanhun sha", "sha" }) );
        set("no_decrease",1);
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("no_get",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "这是蜀中唐门特制的暗器，只有在门派中辈份极高的门人才可以领到。\n这种毒砂此米粒还要小得多，虽然不能打远，可是一发出来就是黑蒙蒙的一大片，\n只要对方在一丈之内两丈方圆间，休想躲得开，只要挨着一粒，就必将腐烂入骨。\n");
                set("value", 0);
                set("base_unit","把");
                set("material", "steel");
                set("unit","把");
        }
        set("rigidity",500000);
        set("weapon_prop/attack",this_player()->query_skill("mantian-huayu",1)/7);
        set("weapon_prop/dodge",this_player()->query_skill("mantian-huayu",1)/4);
        set("poison/type","tm_poison");
        set("poison/amount",this_player()->query_skill("mantian-huayu",1)*10);
        set_amount(1);
        init_throwing(300);
        setup();
}

int wield()
{
        if( this_player()->query_skill("mantian-huayu",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
          int skill;
          skill=this_player()->query_skill("mantian-huayu",1);
               if (damage_bonus < 0 ) return 0;
          if(skill>random(399))
    //    if(random(3)>0)
   //            if(random(3)==0)         
          victim->update_condition("tm_poison");
          victim->start_busy(1);

        return this_object()->name()+ HIG "击中了$n的$l，$n只觉得浑身上下一阵麻痒难当，\n"+HIB"伴随着杀猪般的嚎叫，$n立刻就地翻滚起来！\n" NOR;
}

int query_unparryable(object me,object victim)
{
        object weap;
      
        return 80; 
}

int query_undodgeable(object me,object victim)
{
        object weap;
      
        return 80; 
}
                                       

