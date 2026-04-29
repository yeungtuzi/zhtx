//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 混世魔剑

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit SWORD;
//inherit F_UNIQUE;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIW"混世"+HIR"魔"+HIC"剑"NOR, ({ "hunshi mojian", "jian" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
//        set("no_drop",1);
        set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "这是传说中的混世魔剑，据说每次它一出世，江湖中便是一片腥风血雨。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
    set("weapon_prop/attack", this_player()->query_skill("mo-jian-jue",1)/7);  
    set("weapon_prop/parry", this_player()->query_skill("mo-jian-jue",1)/4);  
        set("wield_msg", HIY"只见$N长叹一声，无可奈何地从空中把出一把混世魔剑。\n"
                HIR "\n你看见天空中一道闪电化过 ....\n\n"
                MAG     "江湖中人都知道：" HIR "混世魔剑要\n\n"
                        "\t\t重新出世了！！！！！！！！！！ ！\n\n" NOR);
        set("unwield_msg", HIW"$N一把将混世魔剑掷入地下，禁不住潸然泪下。\n" NOR);

       }
    init_sword(300);
       setup();
}

int wield()
{
/*
   object owner;
   mapping weapon_prop,equips;
    string *apply, type; 
   string file;
*/
        if( this_player()->query_skill("mo-jian-jue",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }

/*
   apply = keys(weapon_prop);
   for(int i = 0; i<sizeof(apply); i++)
     equips->add_temp("apply/" + applyi, weapon_propapply);
   return 1;
*/
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weap;
        int    wap,wdp;
        string weap_name;
               if (damage_bonus < 0 ) return 0;

        if(victim == me) return;
        
        if( objectp(weap = victim->query_temp("weapon")) )
        {

                wap = weight() / 500
                        + query("rigidity")
                        + me->query("str");

                wdp = (int)weap->weight() / 500
                        + (int)weap->query("rigidity")
                        + (int)victim->query("str");

                      if(  random(wap) > wdp )
                {
                        weap_name = weap->query("name");
                        weap->unequip();
                        weap->move(environment(victim));
                        weap->set("name", "断掉的" + weap->query("name"));
                      weap->set("value", 0);
                        weap->set("weapon_prop", 0);
                        weap->set("long", weap->query("long")+"可是，现在却已经断为两截，不知道还有什么用处。\n");
                        victim->reset_action();
                        return "只听$N一声暴喝，$n手中的" + weap_name
                                + "已被$N挟雷霆万钧之势砸断！\n";
                }
                                
        }
        else 
        victim->receive_wound("kee",damage_bonus/4);
        victim->receive_wound("sen",damage_bonus/8,me);
        return this_object()->name()+ HIR "在$n的$l轻轻划过，$n的伤口立刻觉得如同火烧一般疼痛，顿时鲜血狂飙！\n"+HIW"混世"+HIR"魔"+HIC"剑"+HIC"发出异样的光芒，使$n不由得打了一个寒战！\n" NOR;
}
void init()
{
        if( this_player()==environment() )
            add_action("do_pray","pray"); 
}

int do_pray(string arg)
{
      string name;
      string home;
      object *inv;
      int i;
       name = (string)this_player()->query("name");
        if( this_player()->is_busy() )
                return notify_fail("你正忙着呢，还是省省吧，飞来飞去的很好玩么？\n");

         if( !arg || arg!="start" ) return notify_fail("你要祈求什麽? \n");
         {
         message_vision(HIW"$N披发仗剑，喃喃的吟诵....\n"
             "全身不断的发出闪耀的光芒。 突然一道霹雳.... \n"NOR,this_player() );
         this_player()->receive_damage("sen",10);
         if( random(3) ) return(1);     
         inv = all_inventory(this_player());
                for( i=0;i<sizeof(inv);i++) {
                        if( inv[i]->is_character() )
                                return 1;
                }
        home = this_player()->query("startroom");  
         tell_room(environment(this_player()),
               name+HIC"的身影消失在空气中。\n"NOR,this_player() );
         tell_room(home,
              name+HIC"的身影出现在一阵烟雾之中。\n"NOR,this_player() );
         this_player()->move(home);
          }
          return 1;
}


