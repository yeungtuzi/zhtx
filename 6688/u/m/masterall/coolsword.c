//coolsword.c 混世魔剑
//by tang

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIW"混世"+HIR"魔"+HIC"剑"NOR, ({ "hunshi mojian", "jian" }) );
        set_weight(1);
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

                       }
    init_sword(250);
       setup();
}

                                       

mixed hit_ob(object me, object victim, int damage_bonus)
{                                      
        mapping armors;     
        string *armortype;
        int i;
        object ob;

        if( (random(damage_bonus)+damage_bonus/2) < 200 ) return;
        if( me->query("force") < 200 ) return;                   
//      if( victim->query_temp("apply/armor") < 25 ) return;
        
        armors = victim->query_temp("armor");
        if( !mapp(armors) ) return;
        
        me->add("force",-200);
        if( me->query("force") < 1 ) me->set("force",0);
        
        armortype = keys(armors);
        if( !(i=sizeof(armortype)) ) return;
        
        while(i--)
        {       
                if( !objectp(ob = armors[armortype[i]]) ) continue;
                ob -> unequip();
                ob -> set("name", "破烂的"+ob->query("name"));
                ob -> set("armor_prop",0);
                ob -> set("long", ob->query("long") + ",\n只是可惜现在中间破了个大洞,看来没什么用处了.\n" );
                ob -> set("value",0);
                ob -> move(environment(victim));
        }
        
        victim->receive_wound("kee",damage_bonus/5);
        if( !userp(victim) )
        {
                victim->set_temp("apply/armor", -100);
                victim->set_temp("apply/armor_vs_force",0);
                victim->set_temp("apply/defense",0);
                victim->set_temp("apply/dodge",0);
        }

        return HIG"$N运足内力一逼,"+this_object()->name()+HIG"剑端发出尺许绿幽幽的剑芒,劈开了$n的层层护甲.\n"NOR;

}

