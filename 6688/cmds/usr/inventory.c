// Create by dongsw@zhtx2

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i;
        object *inv,*inv_weapon,*inv_armor,*inv_magic,*inv_medicine,*inv_other,
               *inv_money,*inv_food,*inv_water,ob;
        string str;

        if( wizardp(me) && arg ) {
                ob = find_player(arg);
                if( !ob ) ob = find_living(arg);
                if( !ob ) ob = present(arg, environment(me));
        }

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

int help (object me)
{
        write(@HELP
指令格式: inventory,i

列出您身上所带的物品

[武] 表示武器
[防] 表示防具
[魔] 表示带魔力装备
[药] 表示药品
[钱] 表示钱财
[食] 表示食物
[水] 表示饮水
[杂] 表示杂物

HELP
);
        return 1;
}

