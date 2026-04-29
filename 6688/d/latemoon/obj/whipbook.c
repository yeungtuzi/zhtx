//whipbook.c

inherit ITEM;

void create()
{
        set_name("基本鞭法", ({ "whipbook" }));
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这本书的纸张都已经泛黄了，上面写的是鞭法的入门知识 \n");
                set("value", 20);
                set("material", "paper");
                set("skill", ([
                        "name":                 "whip",                 // name of the skill
                        "exp_required": 0,                              // minimum combat experience required
                                                                              
// to learn this skill.
                        "sen_cost":             20,                             
// gin cost every time study this
                        "difficulty":   15,                             // the base int to learn this skill
                                                                                 
// modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    50,                             // the maximum level you can learn
                                                                                   
// from this object.
                ]) );
      }
}
                                                                                                                                                                                                                                                                                                                                                                                                                         