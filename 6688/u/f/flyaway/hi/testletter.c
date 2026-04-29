// chicken_leg.c
// chicken_leg.c
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void setup()
{}

string status_color(int current, int max);

void init()
{
        add_action("do_eat", "eat");
        add_action("do_addspi", "addspi");
        add_action("do_addwlsw", "addwlsw");
        add_action("do_full", "full");
        add_action("do_grow", "grow");
        add_action("do_ii", "ii");
        add_action("do_hhp", "hhp");
        add_action("do_growdai", "growdai");
}

void create()
{
        seteuid(getuid());
        set_name("烤鸡腿", ({ "fried chicken leg", "chicken", "leg" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一枝烤得香喷喷鸡腿，你还犹豫什麽？分泌胃液吧。\n");
                set("unit", "根");
           set("food_supply",-1);
                set("value", 30);
              //  set("no_get",1);
                        //      set("no_give",1);
                        //      set("no_drop",1);
                        //      set("no_paimai",1);
            //    set("no_sell",1);
                set("wield_msg", "$N抓起一根$n，握在手中当武器。\n");
                set("material", "bone");
        }
        init_hammer(1);
        setup();
}

int do_eat(string arg)
{
       object me,ob;
       me=this_player();
       ob = this_object();
       if( !this_object()->id(arg) ) return 0;
       if (me->query("kar")<30)me->add("kar",random(2));
      if (me->query("per")<30)me->add("per",random(2));
      if (me->query("elo")<30)me->add("elo",random(2));
      if (me->query("msc")<30)me->add("msc",random(2));
      if (me->query("wil")<30)me->add("wil",random(2));
      if (me->query("vis")<30)me->add("vis",random(2));
    //  if (me->query("spi")<30)me->add("spi",random(2));
       tell_object(me,HIG"你吃下一根鸡腿，觉得味道真不错!\n"NOR);
       return 1;
}

int do_addspi()
{
        object me;
        me=this_player();
        me->add("spi",1);
        return 1;
}


int do_addwlsw()
{
        object me;
        me=this_player();
        me->add("wlshw",1);
        tell_object(me,HIG"你感觉声势一震!\n"NOR);
        return 1;
}

int do_full()
{
        object me = this_player();

                       me->set("gin", (int)me->query("max_gin"));
                                   me->set("eff_gin", (int)me->query("max_gin"));
                                  me->set("kee", (int)me->query("max_kee"));
                                  me->set("eff_kee", (int)me->query("max_kee"));
                                  me->set("sen", (int)me->query("max_sen"));
                                  me->set("eff_sen", (int)me->query("max_sen"));
                                  me->set("atman", 2*(int)me->query("max_atman"));
                                  me->set("force", 2*(int)me->query("max_force"));
       me->set("mana", 2*(int)me->query("max_mana"));
       me->set("food",me->max_food_capacity());
           me->set("water",me->max_water_capacity());
        tell_object(me,HIW"你感觉浑身一阵轻松!\n"NOR);
                     return 1;
}

int do_grow()
{
        int questoktime;
        object me = this_player();
        questoktime=me->query("quest_ok");
        if(questoktime<10) me->set("quest_ok",10);
        me->add("faith",3+random(4));
                        me->add("potential",300);
                me->add("combat_exp",1800+random(200));
                me->add("nquestok",1);
                tell_object(me,HIY"你突然感觉灵光一闪，似乎自身修为有了显著提高！\n"NOR);
                return 1;
}

int do_ii(string arg)
{
        int i;
        object *inv,*inv_weapon,*inv_armor,*inv_magic,*inv_medicine,*inv_other,
               *inv_money,*inv_food,*inv_water,ob,me;
        string str;

                me=this_player();
                ob = find_player(arg);
                if( !ob ) ob = find_living(arg);
                if( !ob ) ob = present(arg, environment(me));

        if( !ob ) ob = me;

        inv = all_inventory(ob);
        inv_weapon = filter_array(inv, (: $1->query("weapon_prop")&& !$1->query("adv_props")&& !$1->query("money_id") :));
        inv_armor = filter_array(inv,(: $1->query("armor_type")&& !$1->query("adv_props") :));
        inv_magic = filter_array(inv,(: $1->query("adv_props") :));
        inv_medicine = filter_array(inv,(: $1->query("medicine") :));
          inv_money = filter_array(inv,(: $1->query("money_id") :));
        inv_food = filter_array(inv,(: sizeof($1->query("food_supply"))>0 :));
        inv_water = filter_array(inv,(: sizeof($1->query("max_liquid"))>0 :));
        inv_other = inv - inv_weapon - inv_armor - inv_magic - inv_medicine - inv_money
                    - inv_food - inv_water;
        if( !sizeof(inv) ) {
                write((ob==me)? "目前你身上没有任何东西。\n"
                        : ob->name() + "身上没有携带任何东西。\n");
                return 1;
        }
        str  = HIY"  [总共：%s件]  [负重：%d%%]\n"NOR;
        str += HIY"────────────────\n"NOR;
        if (sizeof(inv_weapon)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_armor)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_magic)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_medicine)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_money)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_food)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_water)>0)str += "%s\n";
        else str+="%s";
        if (sizeof(inv_other)>0)str += "%s\n";
        else str+="%s";
        printf(str,
                chinese_number((int)sizeof(inv)),
                (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
                implode(map_array(inv_weapon, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_armor, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_magic, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_medicine, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_money, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_food, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_water, "inventory_desc", this_object()), "\n"),
                implode(map_array(inv_other, "inventory_desc", this_object()), "\n"),

                );

        return 1;
}

string inventory_desc(object ob)
{
        string str;
        str=MAG"[杂]"NOR;
        if (ob->query("weapon_prop")) str=HIR"[武]"NOR;
        if (ob->query("armor_type")) str=HIW"[防]"NOR;
        if (ob->query("adv_props")) str=HIM"[魔]"NOR;
        if (ob->query("medicine")) str=HIG"[药]"NOR;
          if (ob->query("money_id")) str=HIY"[钱]"NOR;
        if (ob->query("food_supply")) str=HIC"[食]"NOR;
        if (ob->query("max_liquid")) str=HIC"[水]"NOR;

        return sprintf(HIY"  "NOR+str+"%s%s",
                ob->query("embedded")? HIR "√" NOR:
                ob->query("equipped")? HIC "□" NOR:"  ",
                ob->short()
        );

}

int do_hhp(string arg)
{
        object ob,me;
        mapping my;

     //   seteuid(getuid(me));

        me=this_player();
        if(!arg) ob = me;
        else {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看谁的状态？\n");
        }

        my = ob->query_entire_dbase();

    printf(" 精  ： %s%4d/ %4d %s(%3d%%)" NOR "    灵力： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],      my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),     my["eff_gin"] * 100 / my["max_gin"],
                status_color(my["atman"], my["max_atman"]),     my["atman"], my["max_atman"],
                my["atman_factor"] );
    printf(" 气  ： %s%4d/ %4d %s(%3d%%)" NOR "    内力： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
                my["force_factor"] );
    printf(" 神  ： %s%4d/ %4d %s(%3d%%)" NOR "    法力： %s%4d / %4d (+%d)\n" NOR,
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
                status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
                my["mana_factor"] );
    printf(" 食物： %s%4d/ %4d      " NOR "     潜能： %s%d\n" NOR,
        status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),
        HIY,
        (int)ob->query("potential") - (int)ob->query("learned_points"));
    printf(" 饮水： %s%4d/ %4d      " NOR "     武学： %s%d\n" NOR,
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),
        HIM,
        my["combat_exp"] );
    printf("                         " NOR "    商业： %s%d\n" NOR,
        HIM,
        my["magic_exp"] );

    printf(HIC" ------ 纵横天下II ------ " NOR "   政治:  %s%d\n" NOR,
        HIM,
        my["tactic_exp"] );

        return 1;
}

string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

void do_growdai()
{
                        object me;
                        int exp,faith,ctfaith,pot;
                        me=this_player();
                        exp = 350 + random(250);
                faith = 1 + random(4);
                ctfaith = random(2);
                pot = 60 + random(50);
                me->add("combat_exp", exp);
                            me->add("potential", pot);
                                me->set("letter_quest", 0);
                                me->add("faith", faith);
                                me->add("ct_faith", ctfaith);
                return;
}

