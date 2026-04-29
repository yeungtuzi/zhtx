// xiandan.c

//inherit COMBINED_ITEM;
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"灵葫仙丹"NOR,({"xiandan"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                "这是一粒金光四射的仙丹。\n");
        set("unit","粒");
        set("value", 500000);
        set("base_value", 500000);
        set("base_unit", "粒");
        set("base_weiht",500);
        }
       // set_amount(1);
       set("unpawnable",1);
       set("no_paimai",1);
}

void init()
{
        add_action("eat_xiandan","eat");
}


int eat_xiandan(string arg)
{
       object me,ob;
       int forcek,atmank,manak;

       if( !this_object()->id(arg) ) return 0;

       me = this_player();
       ob = this_object();
    
       forcek=me->query("max_force");
       atmank=me->query("max_atman");
       manak=me->query("max_mana");

        if( ob->query("owner") != me )
                return notify_fail("这个东东又不是你的，好意思吃别人历经千辛万苦得来的仙丹吗？\n");

        if ((int)me->query_condition("xiandan_drug" ) > 0 )
        return notify_fail("你不是刚刚服用了一枚仙丹了吗？嗑那么多药干什么！\n");

       me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
if ( random(5) > 3)
        {message_vision(HIR "$N吃下一粒灵葫仙丹，只觉得味道有些奇怪，原来神仙也做假货，这是一件残次

品！\n$N顿时觉得肝肠寸断，五脏欲裂，脑子要裂开了般的疼痛！\n" NOR, me);
                me->add("max_force", -20);
                me->add("max_atman", -20);
                me->add("max_mana", -20);
         message_vision(HIB "$N全身渗出血红色的汗珠，$N中的九阴化骨毒发作了！\n" NOR, me); 
         message("system",
    HIM "\n【谣言】江湖传说(XIANDAN)：听说"+me->name()+"服用了假冒的灵葫仙丹，昏死过去了。\n"+HIC"

【闲聊】"+me->name()+"满腔怨怒地喊着:打倒臭泥潭!打倒道全!!!\n" NOR,users() );
                me->apply_condition("ninemoonpoison",20);
                me->unconcious();
                me->update_condition();
                me->clear_condition();
              me->apply_condition("xiandan_drug", 1000);
        }else{
        message_vision( HIY"$N吃下一粒灵葫仙丹，只觉得精神百倍，一种脱胎换骨的感觉! \n"NOR,me);
        me->apply_condition("xiandan_drug", 500);

      if(me->query("max_force") > 8000) 
                        me->set("max_force",forcek); 
                else {  
                        me->add("max_force", 50+random(50));
                }

      if(me->query("max_atman") > 4000) 
                        me->set("max_atman",atmank); 
                else {  
                        me->add("max_atman", 40+random(40));
                }
      if(me->query("max_mana") > 4000) 
                        me->set("max_mana",manak); 
                else {  
                        me->add("max_mana", 40+random(40));
                }

       me->set("gin", (int)me->query("max_gin"));
        me->set("eff_gin", (int)me->query("max_gin"));
       me->set("kee", (int)me->query("max_kee"));
       me->set("eff_kee", (int)me->query("max_kee"));
       me->set("sen", (int)me->query("max_sen"));
       me->set("eff_sen", (int)me->query("max_sen"));
       me->set("atman", (int)me->query("max_atman"));
       me->set("force", (int)me->query("max_force"));
       me->set("mana", (int)me->query("max_mana"));
              }
 
       destruct(this_object());
        return 1;
}


