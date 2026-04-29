//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 混世魔剑


#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;


void create()
{
        set_name(HIW"混世"+HIR"魔"+HIC"剑"NOR, ({ "hunshi mojian", "jian" }) );
        set_weight(1);
        set("no_sell",1);
        set("no_drop",1);
        set("no_paimai",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "这是传说中的混世魔剑，据说每次它一出世，江湖中便是一片腥风血雨。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
        set("wield_msg", HIY"只见$N长叹一声，无可奈何地从空中把出一把混世魔剑。\n"
                HIR "\n你看见天空中一道闪电化过 ....\n\n"
                MAG     "江湖中人都知道：" HIR "混世魔剑要\n\n"
                        "\t\t重新出世了！！！！！！！！！！ ！\n\n" NOR);
        set("unwield_msg", HIW"$N一把将混世魔剑掷入地下，禁不住潸然泪下。\n" NOR);

                set("adv_props/attack", 20);  
                set("adv_props/parry", 20);  
       }
    init_sword(300);
       setup();
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("mo-jian-jue",1) < 200)
        {
                return notify_fail("你的魔剑诀等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这柄剑。\n");
        }
        return ::wield();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{                                      
        int armor,avf,skill;
        armor=victim->query_temp("apply/armor");
        avf=victim->query_temp("apply/armor_vs_force");
        skill=me->query_skill("mo-jian-jue",1)/3;
        if (damage_bonus < 0 ) return 0;
        if(random(3)>0)
        victim->add_temp("apply/armor", -armor/4 - skill);
        victim->add_temp("apply/armor_vs_force", -avf/4 - skill);
        victim->receive_wound("kee",damage_bonus/6);
     
        if( victim->query_temp("apply/armor") < 0 ) victim->set_temp("apply/armor", 0);
        if( victim->query_temp("apply/armor_vs_force") < 0 ) victim->set_temp("apply/armor_vs_force", 0);

        return HIG"$N运足内力一逼,"+this_object()->name()+HIG"剑端发出尺许绿幽幽的剑芒,刺穿了$n的层层护甲.\n"NOR;

}

