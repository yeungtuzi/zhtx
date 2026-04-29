inherit ITEM;

void create()
{
        set_name("青城心法" , ({ "qingcheng-force" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是青城祖传的心法秘芨.\n");
        set("skill", ([
                "name":                 "qingcheng-force",      
                "exp_required": 30000,       
                "sen_cost":             30,
                "difficulty":   30,
                "base_skill":30,
                "max_skill":    100     
        ]) );
}
      
