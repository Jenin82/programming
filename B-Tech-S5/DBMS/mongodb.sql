1. Create database
-> use jenin

switched to db jenin


2. Create table/collection
-> db.createCollection("test")

{ "ok" : 1 }


3. Insert values to collection
-> db.test.insertMany( [
    { _id: 101, item: "box", qty: 20 },
    { _id: 104, item: "pencil", qty: 15 },
    { _id: 102, item: "pen", qty: 5 },
    { _id: 103, item: "eraser", qty: 8 },
    { _id: 105, item: "scale", qty: 2 }, 
])

{ "acknowledged" : true, "insertedIds" : [ 104, 102, 103, 105 ] }


4. Read Collection
-> db.test.find().pretty()

{ "_id" : 101, "item" : "box", "qty" : 20 }
{ "_id" : 104, "item" : "pencil", "qty" : 15 }
{ "_id" : 102, "item" : "pen", "qty" : 5 }
{ "_id" : 103, "item" : "eraser", "qty" : 8 }
{ "_id" : 105, "item" : "scale", "qty" : 2 }

5. Update collection
-> db.test.update(
   { _id: 101 },
   {
     $set: {
       item: "big-box",
       qty: 10,
     }
   }
)

WriteResult({ "nMatched" : 1, "nUpserted" : 0, "nModified" : 1 })

Result:
{ "_id" : 101, "item" : "big-box", "qty" : 10 }
{ "_id" : 104, "item" : "pencil", "qty" : 15 }
{ "_id" : 102, "item" : "pen", "qty" : 5 }
{ "_id" : 103, "item" : "eraser", "qty" : 8 }
{ "_id" : 105, "item" : "scale", "qty" : 2 }


6. Delete Collection item
-> db.test.remove( { _id: 101 } )

WriteResult({ "nRemoved" : 1 })

Result:
{ "_id" : 104, "item" : "pencil", "qty" : 15 }
{ "_id" : 102, "item" : "pen", "qty" : 5 }
{ "_id" : 103, "item" : "eraser", "qty" : 8 }
{ "_id" : 105, "item" : "scale", "qty" : 2 }


7. Drop Collection
-> db.test.drop()

true