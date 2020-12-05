# 데이터베이스 응용
하석재 강사님 데이터베이스 응용 정리

## 데이터베이스 기본

##### RDBMS
- 데이터베이스는 `데이터를 CRUD(Create, Retrieve, Update, Delete)하는 시스템`
- 관계형 데이터베이스는 `테이블 기반(Table based)으로 데이터 저장하는 시스템`
- 조인
  - 외래 키나 중첩 쿼리(서브 쿼리)를 통해 2개 이상의 테이블을 합치는 연산
  - 테이블이 여러 개로 나눠진 상태에서 원하는 데이터를 찾을 때는 테이블을 합치는 조인 연산을 통해 데이터를 검색
  - 테이블 간의 공통 칼럼인 외래키를 통해서 내부 조인과 외부 조인를 통해서 테이블 단위 검색
  - A join B -> A: 드라이빙 테이블, B: 드리븐 테이블
  - Inner Join: 드라이빙 테이블이든 드리븐 테이블이든 널값이면 누락 됨
  - Outer Join
    - Left: 드라이빙 테이블의 레코드가 누락되면 안 됨
    - Right: 드리븐 테이블의 레코드가 누락되면 안 됨
    - Full Join: 양쪽 모두 누락되면 안 됨
- 인덱스
  - 관계형 데이터베이스는 쓰기보다는 읽기를 빠르게 할 수 있는 데이터베이스로 B 트리 또는 B+ 트리 형태의 `인덱스 자료구조`를 통해서 검색 속도를 향상시킴
  - 인덱스 자료구조는 읽기 성능은 향상시키나 쓰기 성능은 떨어뜨리는 단점이 존재
- 트랜잭션
  - 관계형 데이터베이스는 트랜잭션이라는 기술을 통해서 SQL 쿼리를 실행의 원자성/일관성/격리성/내구성을 보장
  - `몽고DB`를 제외한 대부분의 NoSQL은 트랜잭션을 지원하지 않음
- 데이터
  - 정형 데이터: 스키마에 따른 데이터 저장, RDBMS의 데이터
  - 반정형 데이터: 명확한 스키마가 없는 어느 정도의 자유도를 허용, JSON
  - 비정형 데이터: 스키마가 없음, 멀티미디어 데이터 또는 일반 텍스트
- 객체 관계 모델링(Entity Relationship Modeling)
  - 엔티티: 기본 테이블
  - 릴레이션쉽: 엔티티간의 관계를 표한히기 위해 유도된 테이블
  - 논리 모델링: 업무를 분석하여 그에 대한 데이터 집합/관계를 중점적으로 표현하는 것
    - 테이블을 좀 더 세분하게 `기본 테이블인 엔티티`와 `유도된 테이블인 릴레이션십`으로 구분
  - 물리 모델링: 논리 모델링의 산출물을 시스템으로 어떻게 표현할지 고려하는 것
    - 일반적으로 논리 모델링의 결과를 조금 더 축소시킴
    - 1:1과 1:N 대응 수를 가지는 경우는 중간 릴레이션십을 삭제한 후 1:1인 경우 엔티티에 칼럼으로 추가하고 1:N인 경우 외래키로 엔티티 간 직접 연결
    - N:M인 경우에만 엔티티와 릴레이션십을 남겨둠
  - 모델링 표기법
    - 피터 첸 표기법(ERD)이나 까마귀 발 표기법을 많이 사용
    - 피터 첸은 엔티티와 릴레이션십 표현이 쉬움
    - 까마귀 발은 1:1, 1:N, N:M 대응 수 표현이 쉬움 
- 정규화
  - 데이터의 중복을 정규화(Normalization)를 통해 테이블을 쪼개서 중복성 제거
  - 제1 정규형: `컬럼 값이 원자값을 가지지 않으면` 레코드를 분리하여 테이블 구성
  - 제2 정규형: `키 컬럼과 나머지 일반 칼럼이 직접적인 연관관계(직접 종속)가 없을 때는 테이블을 분리`하여 구성
  - 제3 정규형: `일반적인 컬럼끼리 간접적인 연관관계(간접 종속)를 가지지 않도록 테이블을 분리`하여 구성
  - BCNF 정규형: 제 3정규형의 강화버전
- 외래키
  - 다른 테이블의 기본 키인 칼럼
  - 두 테이블 간의 공통 컬럼
  - 테이블 조인 시 기준이 되는 칼럼
  - FK가 PK인 경우 식별관계라고 하고 FK가 일반 컬럼인 경우 비식별관계라고 함
- 참조무결성 제약조건(Referential Integrity)
  - 외래키로 연결되어 있는 테이블의 경우에는 외래키로 연결 테이블을 검색하면 데이터가 존재해야함
  - 삽입 시에 연결 테이블에 레코드를 먼저 추가하고 레코드를 추가해야함
  - 삭제 시에 연결 테이블의 레코드를 먼저 삭제하고 레코드를 삭제해야함
  
##### SQL
- SQL: RDBMS의 표준 질의어(Query Language)
- `DML(Data Manipulation Language)`
  - 데이터를 직접 접근해 조작을 담당
  - CRUD(INSERT, SELECT, UPDATE, DELETE)
- `DDL(Data Definition Language)`
  - 스키마에 대한 CRUD를 담당
  - CREATE DATABASE, CREATE TABLE, ALTER TABLE, DROP TABLE, RENAME, TRUNCATE TABLE
- `DCL(Data Control Language)`
  - 사용자(역할)별 접근권한(데이터베이스, 테이블별 CRUD)을 담당
  - GRANT, REVOKE
- `TCL(Transaction Control Language)`
  - 트랜잭션 관련된 처리를 담당
  - COMMIT, ROLLBACK, SAVEPOINT
 
## 트랜잭션

##### 트랜잭션
- 데이터베이스의 상태를 변환시키는 하나의 논리적 기능을 수행하기 위해 `한꺼번에 모두 수행되어야 할 일련의 연산`
- All or Nothing (커밋 or 롤백)
- 여러 줄의 SQL쿼리를 실행할 때 장애가 발생했을 경우를 대비해 RDBMS에서 지원하는 `쿼리 전체를 취소하거나 확정하는 기능`을 제공
- 트랜잭션의 ACID 특성
  - `원자성(Atomicity)`: 트랜잭션과 관련된 작업들이 부분적으로 실행되다가 중단되지 않는 것을 보장해야함
  - `일관성(Consistency)`: 트랜잭션을 수행하기 전이나 후나 데이터베이스는 항상 `일관된 상태`를 유지해야함
  - `격리성(Isolation)`: 트랜잭션을 수행 시 다른 트랜잭션의 연산 작업이 끼어들지 못하도록 보장해야함
  - 내구성(Durability): 성공적으로 수행된 트랜잭션은 영원히 반영되어야함
- MySQL은 특이하게 선택할 수 있는 내부 `스토리지 엔진`에 따라 인덱스, 트랜잭션, 락, 조인의 지원 여부가 다름
- MYSQL = `MySQL 엔진 + 스토리지 엔진`
  - MySQL 엔진: SQL interface + Parser + Optimizer + Cache/Buffer
  - 스토리지 엔진: MyISAM 또는 InnoDB(기본 값)
    - show engines;


##### MySQL 스토리지 엔진
- MyISAM
  - 가장 오래된 엔진
  - 트랜잭션과 외래키가 지원이 되지 않음
  - 테이블락
- `innoDB`
  - 트랜잭션과 외래키 지원
  - 레코드락
- Memory
  - 임시 테이블 엔진
  - 트랜잭션과 외래키가 지원이 되지 않음
  - 읽기 성능이 우수하고 쓰기 성능이 떨어짐
  - 테이블락

## 트랜잭션 원자성
##### 락
- 여러 개의 트랜잭션/쓰레드가 공유자원(데이터베이스/테이블/레코드)에 동시에 접근을 시도하여 데이터가 변경되는 경우 동기화를 맞춰주기 위한 기능
- 락의 종류
  - 글로벌 락: 특정한 명령이 수행되면 다른 모든 명령어가 수행이 정지되는 형태의 락
  - 테이블 락: 특정 트랜잭션이 해당 `테이블`을 수정하고 있으면 `다른 트랜잭션은 해당 테이블을 접근하지 못함`, 다른 테이블은 접근 허용
  - 레코드 락: 특정 트랜잭션이 해당 `레코드`를 수정하고 있으면 `다른 트랜잭션은 해당 레코드를 접근하지 못함`, 동일 테이블의 다른 레코드는 접근 허용
- MySQL의 InnoDB엔진은 기본 설정이 autocommit 모드(줄단위 커밋)이므로 트랜잭션을 지원할 수 없어 `set autocommit=0;` 같은 명령을 통해서 autocommit 모드를 꺼야함

##### 트랜잭션 명령
- commit: SQL 실행을 확정 짓는 명령
- rollback: 최종 커밋 이전까지 모두 취소하는 명령, DDL 문은 롤백이 안됨
- savepoint: 최종 커밋 이전까지 모두 취소하는게 아니라 특정 지점까지 명령을 취소시키기 위해서 커밋과 함께 그 지점을 저장하는 명령

##### 트랜잭션의 롤백과 커밋을 구현하는 방법
- `Undo Log`
  - 실행 취소 시 사용하는 MySQL의 로그
  - 트랜잭션이 진행중이면 데이터의 값이 생성/수정/삭제가 되면 Commit 여부 포하여 Undo Log에 기록
  - `트랜잭션이 커밋되면 Undo 로그의 해당 레코드에 상태 변경(-> commit)`
  - `트랜잭션이 롤백되면 Undo 로그의 내용을 확인해서 마지막 커밋상태까지 취소(->rollback)`
- Redo Log
  - 다시 실행이 필요할 때 사용하는 MySQL의  로그
  - 주로 크래시 복원용
- 여러 시스템 간의 트랜잭션인 분산 트랜잭션은 WAS/Middleware/라이브러리를 통해 구현

## 트랜잭션 격리성

##### 격리 수준
- 멀티 쓰레드/트랜잭션이 동시에 동일한 테이블 레코드에 접근할 때 적용하는 규칙
- 격리 수준을 `set tx_isolation=’READ-COMMITTED’;` 등으로 설정할 수 있음
- Read Uncommitted
  - 커밋 여부와 관계없이 `현재 레코드 값을 리턴`
  - 가장 낮은 안정성/가장 높은 성능
  - 롤백이 발생하면 Dirty Read 현상 발생 가능
- Read Committed
  - `Commit된 마지막 값을 리턴`
  - 동일한 트랜잭션 안에서 동일한 쿼리의 결과가 다른 Non-Repeatable Read 현상 발생 가능
  - 일반적으로 사용되는 격리 수준
- Repeatable Read
  - 동일한 트랜잭션에서는 중간에 커밋이 일어나도 처음 값으로 쿼리의 값은 항상 일정함
  - 백업이나 복제와 같이 상대적으로 `긴 시간동안 동작하는 트랜잭션에서 안정적인 실행보장이 필요할 경우 사용`
  - 동일한 트랜잭션에서도 새로운 쿼리에 대해서는 Read Committed처럼 쿼리의 결과가 다른 Phantom Read 현상 발생 가능
  - MySQL의 기본 격리 수준
- Serializable
  - 두 개 이상의 트랜잭션은 동시에 수행되지 않음
  - 이전 트랜잭션이 커밋이 되면 다음 트랜잭션을 실행
  - 가장 높은 안정성/가장 낮은 성능


|레벨|Dirty Read|Non-Repeatable Read|Phantom Read|
|------|-----|-----|------|
|Read Uncommitted|가능|가능|가능|
|Read Committed|불가능|가능|가능|
|Repeatable Read|불가능|불가능|가능|
|Serializable|불가능|불가능|불가능|

##### MVCC (Multi-Version Concurrency Control)
- Write 세션이 Read 세션을 블로킹하지 않고 또 Read 세션이 Write 세션을 블로킹하지 않는 서로 다른 세션이 동일 데이터에 접근했을 때 각 세션마다 다른 버전의 데이터를 보장해주는 메커니즘을 의미
- 락없이 읽기 성능을 증가시키는 기술
- 격리 수준이 다를 경우에 락이 걸리지 않고 동시에 읽는 것이 가능
- 동일한 격리 수준에는 `Undo Log를 여러 개 복제해서` 읽기 락이 발생될 확률을 낮춤
- Undo 로그의 발전
  - 트랜잭션의 롤백 지원 -> 트랜잭션의 격리 수준을 지원 -> MVCC를 지원

## 트랜잭션 일관성

##### 일관성과 무결성
- 일관성을 위배한 상황: 데아터의 상태, 조건, 성질 들이 일관적이지 않은 상황
- 무결성을 위배한 상황: 데이터가 깨지는 상황

##### 복제 연산과 일관성 
- 복제: 동일한 DB를 여러 개 만드는 기술
- RDBMS에서 일관성이 있어 길게 보면 `복제 연산에서 동일하게 된다고 가정`
- RDBMS에서 Large-scale 복제를 가정하지 않음


## 복제 

##### VLDB (Very Large DBMS)
- 읽기/쓰기 성능 및 저장용량을 높이기 위한 기술로 보통 `Partitioning/Sharding/Replication/Backup Aggregation` 등을 묶어서 부르는 기술
- 일반적으로 VLDB에서는 외래키가 없어 조인이 안되므로 역정규화를 통해서 중복을 허용

##### 복제
- 동일한 데이터베이스를 트래잭션을 보장하여 여러 개 생성하는 기술
- 장애에 대응하거나 읽기 성능을 높이기 위해서 사용
- 쓰기 성능은 떨어짐
- 마스터/슬레이브 구성
  - 마스터에 쓰고 슬레이브에서 마스터를 읽어서 복제하는 `복제의 방향이 존재`
  - 슬레이브는 읽기만 허용
  - 마스터 1대에 슬레이브 여러 대로 구성
  - 마스터의 내용을 실시간(Real-time) 백업의 성격을 갖는데, 일정 시간을 `지연 복제`할 수도 있음
  - 슬레이브 노드가 너무 많아서 마스터의 성능이 떨어지면 마스터에 머스터 역할을 하는 노드를 하나 더 붙여서 릴레이 노드를 만들어서 분산
- 복제의 방식
  - `비동기 복제`
    - 슬레이브에 내용이 반영되었는지 확인하지 않음
    - 속도는 가장 빠르고 신뢰도가 낮음
    - 슬레이브의 랙(lag) 현상이 존재할수 있음
    - 기본 복제 방식
  - `반동기 복제`
    - 슬레이브 중에 하나는 반영되었는지 확인
    - 속도는 중간이고 신뢰도 중간
  - `동기 복제`
    - 모든 슬레이브가 반영되었는지 확인
    - 속도는 가장 느리고 신뢰도 높음
    - MySQL에서는 지원하지 않음


##### MySQL 복제
- MySQL Binlog Format
  - Statement-based
    - 마스터에 들어온 쿼리를 슬레이브로 복사하는 방식
    - 동일한 쿼리를 실행해도 `시간이나 uuid` 관련 쿼리에서 오류가 발생
  - Row-based
    - 쿼리의 실행 결과를 슬레이브로 보냄
    - 락처리에 유리하여 권장되는 방식
    - 트래픽이 많아지는 단점이 존재
    - 기본 복제 포맷
  - Mixed
    - 기본은 Statement-based 사용하고, 상황에 따라 Row-based를 사용하는 방식
- MySQL의 로그 파일
  - Error Log
  - General Log
    - 모든 로그
    - 성능저하로 보통 사용하지 않음 
  - Slow Query Log
    - 최적화용도로 사용
  - `Binary Log`
    - General Log와 유사하지만 바이너리 형태로 저장되는 로그
    - 복제용(마스터)
  - `Relay Log`
    - 마스터의 Binary Log 카피
    - 복제용(슬레이브)
  - cf) undo log나 redo log는 MySQL이 내부적으로 사용하는 로그
- MySQL 복제 과정
  - 마스터 스레드
    - 슬레이브로 바이너리 로그를 전송하는 쓰레드
  - `Slave IO 쓰레드`
    - 마스터 DBMS에 로그인해서 바이너리로그를 읽어 릴레이 로그에 쓰는 쓰레드
  - `Slave SQL 쓰레드`
   - 릴레이 로그에서 실제 슬레이브 DBMS에 반영하는 쓰레드
- `GTID(Global Transaction IDentifier)`
  - MySQL상의 바이너리 로그/릴레이 로그 안에 있는 트랜잭션 ID
  - 실제 동일한 트랜잭션 임에도 노드별로 다른 값을 유지하는 경우가 있어 이를 막아주는 개념

##### MySQL 고가용성
- 고가용성: 서비스가 `장애가 발생하더라도 계속 운영할 수 있도록 만드는 기술`
- 문제 상황과 수작업으로 할 수 있는 대처법
  - 복제가 진행되는 도중 슬레이브가 죽는다면?
    - 다른 슬레이브가 동작하고 있으면 전체 서비스는 문제 없이 동작하며 새로운 슬레이드를 생성하고 복제를 다시 설정
  - 복제가 진행되는 도중 마스터가 죽느다면?
    - 복제가 정지되며 슬레이브 중에 하나를 마스터로 설정하고 다른 슬레이브는 마스터의 주소를 변경해서 다시 복제를 진행
- 자동화된 대처법
  - `Active-Standby 구성`
    - 마스터가 될 후보 중 2개의 노드를 선정하고 두 개의 마스터 중 Active 마스터가 장애가 발생하면 즉시 Standby 마스터로 마스터를 변경
    - Standby에서 `Active로 전환이 느릴 수 있음`
    - MySQL에서 지원
  - `Active-Active 구성`
    - 두 개 이상의 Active 마스터 노드 구성 허용
    - 하나의 Active 노드의 장애가 발생해도 다른 Active 노드로 서비스
    - 노드들간의 합의가 필요하므로 동 수가 안나오도록 `홀수로 구성`
    - 합의를 위해 `마스터끼리 복제해야하는 상황(Group Replication)이` 필요할 수 있음
    - MySQL은 지원하지 않음
- MySQL의 이중화 기술
  - MHA(MySQL HA)
    - 장애가 났을 경우 슬레이브를 마스터로 승격
    - Active-Standby가 아님
  - `MMM(Multi-master Replication Manager)`
    - 마스터를 이중화 하는 기술
    - Active-Standby 구성
  - MySQL Group Replication
    - EE/Cluester GE 라이선스만 지원
    - 마스터를 이중화 하는 기술


## 백업

##### 백업
- 백업 방법에 대한 분류
  - 논리 백업: SQL 쿼리 형태로 복사
    - 논리 백업의 종류
      - 전체 백업: 전체 전부를 백업
      - 부분 백업: 일부만 백업
      - 증분 백업: 이 전과 달라진 부분만 백업
  - 물리 백업: 데이터를 가진 물리 `파일`을 직접 복사
- 백업 방식에 대한 분류
  - 핫 백업: 서비스를 동작 시키면서하는 백업
  - 콜드 백업: 서버를 정지시키고 백업


##### MySQL 백업
- 덤프를 이용한 백업
  - DBMS 전체 백업: mysqldump -uroot -p --all-databases > dbms.sql
  - 특정 디비 백업: mysqldump -uroot -p 디비이름 > db.sql
  - 특정 테이블 백업: mysqldump -uroot -p 테이블이름 > table.sql
  - 덤프를 이용한 백업은 글로벌 락이 걸림
- 덤프를 이용한 복원
  - 전체 복원: mysql -uroot -p < dbms.sql
  - 특정 디비 복원: mysql -uroot -p 디비이름 < db.sql
  - 특정 테이블 복원: mysql -uroot -p 테이블이름 < table.sql
- 툴을 이용한 백업
  - EnterpriseBackup(유료)
  - XtraBackup(무료)