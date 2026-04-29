inherit ITEM;

void create()
{
    set_name("基本掌法",({"basic strike","book"}));
    set_weight(300);

    if(clonep())
        set_default_object(__FILE__);
    else{
         set("unit","本");
         set("long","这是一武功秘籍。\n");
         set("value",1000);
         set("material","paper");
         set("skill",([
         "name":"strike",
         "exp_required": 500,
         "sen_cost": 10,
         "difficulty": 10,
         "max_skill": 51
         ]));
        }
    setup();
}

         
