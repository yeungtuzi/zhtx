// xiandan.c

//inherit COMBINED_ITEM;
inherit ITEM;

void create()
{
        set_name("灵葫仙丹",({"xiandan"}));
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
}

void init()
{
        add_action("eat_xiandan","eat");
}


int eat_xiandan(string arg)
{
       object me;

       if( !this_object()->id(arg) ) return 0;

       me = this_player();


       me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
        //add_amount(-1);
        message_vision(
 "$N吃下一粒灵葫仙丹，只觉得精神百倍，一种脱胎换骨的感觉! \n",me);
       me->add("max_force", 30);
       me->add("max_atman", 30);
       me->add("max_mana", 30);

//      me->set("max_force",((int)me->query_skill("force", 1) +
//              me->query_skill("force")/5) * 10 );
//      me->set("max_atman",((int)me->query_skill("magic", 1) +
//              me->query_skill("magic")/5) * 10 );
//      me->set("max_mana",((int)me->query_skill("spells", 1) +
//              me->query_skill("spells")/5) * 10 );


       me->set("gin", (int)me->query("max_gin"));
        me->set("eff_gin", (int)me->query("max_gin"));
       me->set("kee", (int)me->query("max_kee"));
       me->set("eff_kee", (int)me->query("max_kee"));
       me->set("sen", (int)me->query("max_sen"));
       me->set("eff_sen", (int)me->query("max_sen"));
       me->set("atman", (int)me->query("max_atman"));
       me->set("force", (int)me->query("max_force"));
       me->set("mana", (int)me->query("max_mana"));
       destruct(this_object());
        return 1;
}

